#include <stdio.h>
#include <stdlib.h>

#define N  1024

int a[N][2];

int cmp(const void *a,const void *b)
{
	return **(int (*)[2])a-**(int (*)[2])b;
}

int main(void)
{
	int c,m,n,i;
	double s;
	scanf("%d",&c);
	while(c--){
		scanf("%d%d",&m,&n);
		for(i=0;i<n;++i){
			scanf("%d%d",a[i],a[i]+1);
		}
		qsort(a,n,sizeof(int [2]),cmp);
		for(s=0,i=0; m>0 && i<n;m-=a[i][0]*a[i][1],++i){
			if(m>a[i][0]*a[i][1]){
				s+=a[i][1];
			} else {
				s+=1.0*m/a[i][0];
			}
		}
		printf("%.2f\n",s);
	}
	return 0;
}

