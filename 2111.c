#include <stdio.h>
#include <stdlib.h>
#define N 128
int a[N][2];

int cmp(const void *a,const void *b)
{
	return **(int (*)[2])b-**(int (*)[2])a;
}

int main(void)
{
	int v,n,s,i;
	while(~scanf("%d",&v) && v){
		scanf("%d",&n);
		for(i=0;i<n;++i){
			scanf("%d%d",a[i],a[i]+1);
		}
		qsort(a,n,sizeof(int [2]),cmp);
		for(i=0,s=0;v>0 && i < n;v-=a[i][1],++i){
			if(v>a[i][1]){
				s+=a[i][1]*a[i][0];
			} else {
				s+=a[i][0]*v;
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
