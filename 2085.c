#include <stdio.h>
#define MAX 33
long long int arr[(MAX+1)*2]={1,0};
int nuclear(i)
{
	long long int a,b;
	a=arr[(i-1)*2];
	b=arr[(i-1)*2+1];
	arr[i*2]=3*a+2*b;
	arr[i*2+1]=a+b;
}
int main()
{
	int i;
	for(i=1;i<(MAX+1);i++){
		nuclear(i);
	}
	/* for(i=0;i<(MAX+1);i++){ */
	/* 	printf("%d:\t%I64d, %I64d\n",i,arr[i*2],arr[i*2+1]); */
	/* } */
	while(scanf("%d",&i)!=EOF && i!=-1){
		printf("%I64d, %I64d\n",arr[i*2],arr[i*2+1]);
	}
	return 0;
}
