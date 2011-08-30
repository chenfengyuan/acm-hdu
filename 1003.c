#include <stdio.h>

int main()
{
	int t,n,i,j,a,b,max_a,max_b;
	int max,s,temp;
	scanf("%d",&t);
	for(i=0;i<t;++i){
		scanf("%d",&n);
		scanf("%d",&max);
		s=max;
		max_a=max_b=a=b=1;
		if(s<0){
			s=0;
			a=b+1;
		}
		
		for(j=1;j<n;++j){
			scanf("%d",&temp);
			b++;
			s+=temp;
			if(s>max){
				max_a=a;
				max_b=b;
				max=s;
			}
			if(s<0){
				s=0;
				a=b+1;
			}
		}
		printf("Case %d:\n%d %d %d\n%s",i+1,max,max_a,max_b,i<t-1?"\n":"");
	}
	return 0;
}
