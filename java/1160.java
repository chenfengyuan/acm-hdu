import java.util.*;

class mouse
{
    public int w,s,p,n,i;
}
class cmp1 implements Comparator<mouse>
{
    public int compare(mouse a,mouse b)
    {
	return a.w-b.w;
    }
}

class Main 
{
    public static final int N=1000;
    public static void main(String[]args)
    {
	mouse []arr=new mouse[N];
	int []q=new int[N];
	Scanner sc=new Scanner(System.in);
	int i=0,j,k,max,max_i;
	mouse []arr2=new mouse[N];
	while(sc.hasNext()){
	    arr[i]=new mouse();
	    arr[i].n=1;
	    arr[i].p=-1;
	    arr[i].w=sc.nextInt();
	    arr[i].i=i+1;
	    arr[i++].s=sc.nextInt();
	}
	Arrays.sort(arr,0,i,new cmp1());
	for(j=1;j<i;++j){
	    for(k=0;k<j;++k){
		if(arr[k].w<arr[j].w&&arr[k].s>arr[j].s){
		    if(arr[k].n>=arr[j].n){
			arr[j].n=arr[k].n+1;
			arr[j].p=k;
		    }
		}
	    }
	}
	max=1;max_i=0;
	for(j=0;j<i;++j){
	    if(arr[j].n>max){
		max_i=j;
		max=arr[j].n;
	    }
	}
	// for(j=0;j<i;++j){
	//     System.out.println(arr[j].i+"\t"+arr[j].w+"\t"+arr[j].s+"\t"+arr[j].p+"\t"+arr[j].n);
	// }
	max=arr[max_i].n;
	j=arr[max_i].n-1;
	while(max_i!=-1){
	    q[j--]=max_i;
	    max_i=arr[max_i].p;
	}
	System.out.println(max);
	for(j=0;j<max;++j){
	    System.out.println(arr[q[j]].i);
	}
    }
}

    
