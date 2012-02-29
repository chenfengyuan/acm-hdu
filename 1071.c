#include <stdio.h>
#include <stdlib.h>
#define P(x) ((x)*(x))
#define T(x) ((x)*(x)*(x))

struct xy
{
	double x,y;
} p[3];

int cmp(const void *a,const void *b)
{
	return ((struct xy *)a)->x-((struct xy *)b)->x;
}

int main(void)
{
	int t,i;
	double a,b,c;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<3;++i){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		qsort(p,3,sizeof(struct xy),cmp);
		
		/* for(i=0;i<3;++i){ */
		/* 	printf("%lf,%lf\n",p[i].x,p[i].y); */
		/* } */
		/* putchar('\n'); */

		b=((p[2].y-p[0].y)/(P(p[2].x)-P(p[0].x))-(p[1].y-p[0].y)/(P(p[1].x)-P(p[0].x)))/((p[2].x-p[0].x)/(P(p[2].x)-P(p[0].x))-(p[1].x-p[0].x)/(P(p[1].x)-P(p[0].x)));
		a=(p[1].y-p[0].y)/(P(p[1].x)-P(p[0].x))-(p[1].x-p[0].x)/(P(p[1].x)-P(p[0].x))*b;
		c=p[0].y-a*P(p[0].x)-b*p[0].x;

		/* for(i=0;i<3;++i){ */
		/* 	printf("%lf,%lf\n",p[i].x,a*P(p[i].x)+b*p[i].x+c); */
		/* } */
		/* putchar('\n'); */
		printf("%.2lf\n",1.0/3*a*(T(p[2].x)-T(p[0].x))+0.5*b*(P(p[2].x)-P(p[0].x))+c*(p[2].x-p[0].x)-(p[0].y+p[2].y)*(p[2].x-p[0].x)/2);
	}
	return 0;
}
