/* http://lcc3536.blog.163.com/blog/static/132469917201132625534222/ */
/* http://xuyemin520.is-programmer.com/posts/26208.html */
#include <stdio.h>
#include <stdlib.h>

#define N 14

int a[N]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};

int find(int num)
{
	int start,end,m,n;
	if(a[num])
		return a[num];
	for(m=1;a[num]==0;++m){
		n=num<<1;
		start=0;
		end=num-1;
		while(n>num)
			if(m%n>=start&&m%n<=end)
				break;
			else{
				start=((start-(m+1))%n+n)%n;
				end=((end-(m+1))%n+n)%n;
				--n;
			}
		if(n==num)
			a[num]=m+1;
	}
	return a[num];
}
		
int main(void)
{
	int n;
	while(~scanf("%d",&n) && n!=0){
		printf("%d\n",find(n));
	}
	
	return 0;
}
