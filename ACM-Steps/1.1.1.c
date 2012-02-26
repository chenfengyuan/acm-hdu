#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#include <stdio.h>

int main(void)
{
	long long a,b;
	while(~scanf(LL LL,&a,&b)){
		printf(LL "\n",a+b);
	}
	return 0;
}
