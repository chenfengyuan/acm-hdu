/* http://blog.csdn.net/a342374071/article/details/6701544 */
#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif
#include <stdio.h>
#define INT32_MIN              (-2147483647-1)
#define N 1000001
#define MAX(x,y) ((x)>(y)?(x):(y))
int num[N];
int dp[2][N];

int main(void)
{
	int m,n,i,j,t;
	long long max=INT32_MIN;
	while(~scanf("%d%d",&m,&n)){
		for(i=1;i<=n;++i){
			scanf("%d",num+i);
			dp[0][i]=dp[1][i]=0;
		}
		/* printf("%d %d %d",m,n,nums[0]); */
		/* for(i=1;i<=n;++i){ */
		/* 	printf(" %d",nums[i]); */
		/* } */
		/* printf("\n"); */
		t=1;
		for(i=1;i<=m;++i,t=!t){
			dp[t][i]=dp[!t][i-1]+num[i];
			dp[!t][i]=MAX(dp[!t][i-1],dp[!t][i]);
			for(j=i+1;j<=n-m+i;++j){
				dp[t][j]=MAX(dp[!t][j-1],dp[t][j-1])+num[j];
				dp[!t][j]=MAX(dp[!t][j-1],dp[!t][j]);
			}
		}
		max=INT32_MIN;
		for(i=m;i<=n;++i){
			max=MAX(dp[m&1][i],max);
		}
		printf(LL "\n",max);
	}
	return 0;
}

