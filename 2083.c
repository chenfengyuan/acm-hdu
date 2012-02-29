#include <stdio.h>
#include <stdlib.h>
int a[510];
int cmpint(const void *p1,const void *p2)
{
	return *(int *)p1>*(int *)p2;
}
int main()
{
	int m,n,i,b,s;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		qsort(a,n,sizeof(int),cmpint);
		s=0;
		b=a[n/2];
		for(i=0;i<n;i++)
			s+=abs(b-a[i]);
		printf("%d\n",s);
	}
	return 0;
}
