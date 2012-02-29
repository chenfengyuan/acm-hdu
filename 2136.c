#include <stdio.h>
#include <string.h>

#define N 1000000
int a[N+1];
void mp(void)
{
	int i,j,k;
	for(i=1;i<=N;i++){
		a[i]=1;
	}
	k=2;
	for(i=2;i<=N;++i){
		if(a[i]==1){
			a[i]=k;
			for(j=i+i;j<=N;j+=i){
				a[j]=k;
			}
			++k;
		}
	}
}

int main(void)
{
	
	int n,i;
	mp();
	while(~scanf("%d",&n)){
		printf("%d\n",a[n]-1);
	}
	return 0;
}
