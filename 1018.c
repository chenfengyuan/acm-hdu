#include <stdio.h>
#include <math.h>

int nth(int n)
{
	double c1 = 0.798179868358; /* lg(2*pi)   */
	double c2 = 0.434294481903; /* lg(e)  */
	long double c3=log10(n);
	if(n<=3){
		return 1;
	} else {
		return (int)((c3+c1)/2+n*(c3-c2)+1);
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&i);
		printf("%d\n",nth(i));
	}
	return 0;
}
