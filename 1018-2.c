#include <stdio.h>
#include <math.h>

int main(void)
{
	int t,n,i;
	double s;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n<=3)
			puts("1");
		else{
			for(i=1,s=0;i<=n;++i)
				s+=log10(i);
			printf("%.0lf\n",ceil(s));
		}
	}
	return 0;
}

