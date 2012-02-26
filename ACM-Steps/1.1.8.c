#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#include <stdio.h>

int main(void)
{
	int a,n,m;
	long long s;
	scanf("%d",&n);
	n--;
	scanf("%d",&m);
	s=0;
	while(m--){
		scanf("%d",&a);
		s+=a;
	}
	printf(LL "\n",s);
	while(n--){
		scanf("%d",&m);
		s=0;
		while(m--){
			scanf("%d",&a);
			s+=a;
		}
		printf("\n" LL "\n",s);
	}
	return 0;
}
