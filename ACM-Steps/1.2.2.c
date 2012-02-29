#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif
#include <stdio.h>

int main(void)
{
	int n;
	long long r,e,c;
	scanf("%d",&n);
	while(n--){
		scanf(LL LL LL,&r,&e,&c);
		if(e-c>r){
			printf("advertise\n");
		}
		else if(e-c==r){
			printf("does not matter\n");
		} else {
			printf("do not advertise\n");
		}
	}
	return 0;
}

