#include <stdio.h>

int main(void)
{
	int n,a,b,s;
	while(~scanf("%d",&n) && (n != 0)){
		s=n*5;
		a=0;
		while(n--){
			scanf("%d",&b);
			if(b>a){
				s+=(b-a)*6;
			} else {
				s+=(a-b)*4;
			}
			a=b;
		}
		printf("%d\n",s);
	}
	return 0;
}

