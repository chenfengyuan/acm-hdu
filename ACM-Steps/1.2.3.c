#include <stdio.h>

#define LEAP(year) (((year)%4==0 && (year%100!=0)) || ((year)%400==0))
#define GET_NTH_LEAP_YEAR(year) ((year)/4-(year)/100+(year)/400)
#define LEAST_YEAR(n) (400*(n)/101)

int main(void)
{
	int i,t,year,n,nth;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&year,&n);
		nth=n+(GET_NTH_LEAP_YEAR(year))-LEAP(year);
		i=LEAST_YEAR(nth);
		while(!(LEAP(i) && (GET_NTH_LEAP_YEAR(i) == nth)))
			++i;
		printf("%d\n",i);
	}
	return 0;
}
