#include <stdio.h>
#include <stdlib.h>

int num[10000];

int compare(const void * a,const void * b)
{
	return *(int *)b-*(int *)a;
}

int main(void)
{
	int n,i,j;
	while(~scanf("%d",&n)){
		for(i=0;i<n;++i){
			scanf("%d",num+i);
		}
		qsort(num,n,sizeof(int),compare);
		printf("%d %d",num[0],num[n-1]);
		for(i=1,j=n-2;i<=j;++i,--j){
			if(i==j){
				printf(" %d",num[i]);
			} else {
				printf(" %d %d",num[i],num[j]);
			}
		}
		printf("\n");
	}
	return 0;
}

	
