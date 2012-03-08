#include <stdio.h>
#include <string.h>
#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define N 36

long long d[N][N];
int main(void)
{
	int i,j,n;
	memset(d,0,sizeof(d));
	for(i=0;i<N;++i){
		d[i][0]=1;
	}
	for(i=1;i<N;++i){
		for(j=1;j<=i;++j){
			d[i][j]=d[i-1][j]+d[i][j-1];
		}
	}
	/* for(i=0;i<N;++i){ */
	/* 	for(j=0;j<N;++j){ */
	/* 		printf("%d ",d[i][j]); */
	/* 	} */
	/* 	puts(""); */
	/* } */
	i=0;
	while(scanf("%d",&n),n!=-1){
		++i;
		printf("%d %d "LL"\n",i,n,d[n][n]*2);
	}
	return 0;
}

