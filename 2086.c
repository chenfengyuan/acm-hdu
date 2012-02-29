#include <stdio.h>

int main()
{
	int n,i;
        double arr[3000];
	double a0,an,a1;
	while(scanf("%d",&n)!=EOF){
		scanf("%lf%lf",&a0,&an);
		for(i=0;i<n;i++){
			scanf("%lf",arr+i);
		}
		a1=n*a0+an;
		for(i=1;i<=n;i++){
			a1-=2*i*arr[n-i];
		}
		printf("%.2f\n",a1/(n+1));
	}
	return 0;
}
