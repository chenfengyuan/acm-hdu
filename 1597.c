#include <stdio.h>
#include <math.h>
#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif


int main(void)
{
	long long k,n,i;
	scanf(LL,&k);
	while(k--){
		scanf(LL,&n);
		for(i=sqrt(2*n)-1;i*(i+1)/2<n;++i)
			;
		--i;
		printf(LL"\n",(n-i*(i+1)/2-1)%9+1);
	}
	return 0;
}

