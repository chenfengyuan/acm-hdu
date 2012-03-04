#include <stdio.h>
#define N 21
long long f[N],stir[N][N];

void solve(void)
{
	int i,j;
	f[0]=1;
	for(i=1;i<N;++i){
		f[i]=i*f[i-1];
	}
	for(i=1;i<N;++i){
		stir[i][0]=0;
	}
	for(i=1;i<N;++i){
		for(j=1;j<=i;++j){
			if(i==j){
				stir[i][j]=1;
			} else {
				stir[i][j]=stir[i-1][j-1]+(i-1)*stir[i-1][j];
			}
		}
	}
	/* for(i=0;i<N;++i){ */
	/* 	for(j=0;j<N;++j){ */
	/* 		printf("%d,%d,%I64d\n",i,j,stir[i][j]); */
	/* 	} */
	/* } */
	return;
}

			
int main(void)
{
	int t,n,k,i;
	double s;
	solve();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=1,s=0;i<=k;++i){
			s+=stir[n][i]-stir[n-1][i-1];
		}
		printf("%.4lf\n",s/f[n]);
	}
	return 0;
	
}

	
