#include <stdio.h>
#define N 100000
int arr[N];

int safep_fast(int n,int m)
{
	int i;
	if(n%2==0 && m%2==0){
		return 1;
	}
	for(i=3;i<=n && i<=m;i+=2){
		if(n%i==0 && m%i==0)
			return 1;
	}
	return 0;
}

int safep(int n,int m)
{
	int i,j;
	for(i=0;i<n;++i)
		arr[i]=1;
	arr[0]=0;
	for(i=m%n,j=n-1;j;i=(i+m)%n){
		if(arr[i]==1){
			--j;
			arr[i]=0;
		}
		if(i==0)
			return 1;
	}
	return 0;
}

int main(void)
{
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		if(safep_fast(n,m))
			puts("YES");
		else
			puts("NO");
	}
	
	/* for(n=1;n<N;++n){ */
	/* 	for(m=1;m<=n;++m){ */
	/* 		if(safep(n,m)!=safep_fast(n,m)){ */
	/* 			printf("\n%d,%d,%d,%d\n",n,m,safep(n,m),safep_fast(n,m)); */
	/* 			return 0; */
	/* 		} */
	/* 	} */
	/* } */
	return 0;
}

		
