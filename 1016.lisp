(defpackage cfy.1016
  (:use :common-lisp))
(in-package :cfy.1016)
(defparameter *n* 19)
(defun primep(n)
  (or (= n 2)
      (and (= 1 (mod n 2))
	   (loop for i from 3 upto (sqrt n) by 2
	      if (= 0 (mod n i))
	      do (return nil)
	      finally (return t)))))
(defun make-adj(n)
  (let ((adj (make-array n)))
    (loop for i from 0 to (1- n)
	 do (setf (aref adj i) (make-array 0 :adjustable t :fill-pointer 0)))
    (loop for i from 1 to n
       do (loop for j from 1 to n
	     if (and (/= i j) (primep (+ i j)))
	     do (vector-push-extend j (aref adj (1- i)))))
    adj))
(defparameter *adj* (make-adj *n*))
(defparameter *number* (make-array *n*))
(defparameter *list* (make-array 0 :adjustable t :fill-pointer 0))
(defparameter *r* (make-array 0 :adjustable t :fill-pointer 0))
(defun init()
  (loop for i from 0 to (1- *n*)
       do (setf (aref *number* i) 1))
  (setf (fill-pointer *list*) 0)
  (setf (fill-pointer *r*) 0))
(defun search-df(i n)
  (setf (aref *number* (1- i)) 0)
  (vector-push-extend i *list*)
  ;; (format t "~a~%" *list*)
  (cond
    ((and (= n (length *list*))
	  (primep (1+ i)))
     (vector-push-extend (make-array n :initial-contents *list*) *r* ))
    ((< (length *list*)n)
     (loop for j across (aref *adj* (1- i))
	if (and (<= j n) (= 1 (aref *number* (1- j) )) (primep (+ j i)))
	do (search-df j n))))
  (vector-pop *list*)
  (setf (aref *number* (1- i)) 1))
(with-open-file (out "/dev/shm/a" :direction :output :if-exists :supersede :if-does-not-exist :create)
	    (loop for i from 1 to 12
	       do (progn (init)(search-df 1 i)
			 (format out "a[~a]=\"" i)
			 (loop for j across *r*
			    do (format out "~{~a~^ ~}\\n" (coerce j 'list)))
			 (format out "\";~%"))))