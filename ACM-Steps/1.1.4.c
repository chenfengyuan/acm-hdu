#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#include <stdio.h>

int main(void)
{
	long long s;
	int n,a;
	while(~scanf("%d",&n) && (n != 0)){
		s=0;
		while(n--){
			scanf("%d",&a);
			s+=a;
		}
		printf(LL "\n",s);
	}
	return 0;
}
