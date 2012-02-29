#include <stdio.h>
int main(void)
{
	int a,b,c,d,t;
	while(~scanf("%d%d",&a,&b)){
		c=a,d=b;
		while(c>0){
			t=d%c;
			d=c;
			c=t;
		}
		printf("%d\n",a*b/d);
	}
	return 0;
}

