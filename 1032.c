#include <stdio.h>

#define N 1000000

int ar[N];

int c(int n)
{
	int p=1,m=n;
	if(ar[m]>0)
		return ar[m];
	
	while(n!=1){
		if(n%2)
			n=3*n+1;
		else
			n/=2;
		++p;
	}
	return ar[m]=p;
}

int main(void)
{
	int a,b,m,i,max,min;
	while(~scanf("%d%d",&a,&b)){
		if(a>b){
			max=a;
			min=b;
		} else {
			max=b;
			min=a;
		}
		
		m=c(min);
		for(i=min+1;i<=max;++i){
			if(c(i)>m)
				m=c(i);
		}
		printf("%d %d %d\n",a,b,m);
	}
	return 0;
}

