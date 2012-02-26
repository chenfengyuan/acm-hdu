#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#include <stdio.h>

int main(void)
{
	int a,b;
	while(~scanf("%d%d",&a,&b)){
	printf(LL "\n\n",(long long)a+b);
	}
	return 0;
}
