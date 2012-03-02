#include <stdio.h>
#include <stdlib.h>
#define N (2*10000)

int a[N];

int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main(void)
{
	int n,m,i;
	while(~scanf("%d%d",&n,&m)){
		for(i=0;i<n;++i)
			scanf("%d",a+i);
		for(i=0;i<m;++i)
			scanf("%d",a+i+n);
		qsort(a,n+m,sizeof(int),cmp);
		printf("%d",*a);
		for(i=1;i<n+m;++i){
			if(a[i]!=a[i-1])
				printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}

	
