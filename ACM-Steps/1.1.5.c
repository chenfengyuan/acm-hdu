#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#include <stdio.h>

int main(void)
{
	long long s;
	int n,a,m;
	while(~scanf("%d",&n)){
		while(n--){
			s=0;
			scanf("%d",&m);
			while(m--){
				scanf("%d",&a);
				s+=a;
			}
			printf(LL "\n",s);
		}
	}
	return 0;
}
