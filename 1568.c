#include <stdio.h>
#include <math.h>

int main(void)
{
	const double gr=(1+sqrt(5))/2;
	const double r5=sqrt(5);

	double n,t,a;
	while(~scanf("%lf",&n)){
		a=pow(10,modf(n*log(gr)/log(10)-log(r5)/log(10),&t));
		a=a*pow(10,(t<3.5?t:3));
		if(t<3.5){
			a+=0.5;
		}
		printf("%d\n",(int)a);
	}
	return 0;
}

