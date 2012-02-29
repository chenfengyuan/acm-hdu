#include <stdio.h>
#include <math.h>

int main(void)
{
	int n,s,i,j,q;
	while(~scanf("%d",&n)){
		s=0;
		while(n--){
			scanf("%d",&j);
			if(j==2){
				++s;
			}
			else if(j%2!=0) {
				q=sqrt(j);
				for(i=3;i<=q;i+=2){
					if(j%i==0)
						break;
				}
				if(i>q)
					++s;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
