#include <stdio.h>
#include <math.h>
#
int main(void)
{
	int t;
	long long n;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d",&n);
		printf("%d\n",(int)(pow(10.0,n*log10(n)-(long long)(n*log10(n)))));
	}
	return 0;
}

