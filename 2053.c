#include <stdio.h>
#include <math.h>

int main(void)
{
	int n,r;
	while(~scanf("%d",&n)){
		r=sqrt(n);
		if(r*r==n){
			puts("1");
		} else {
			puts("0");
		}
	}
	return 0;
}

