#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int s[N][2];
int cmp1(const void *a,const void *b)
{
	int *c=*(int (*)[2])a;
	int *d=*(int (*)[2])b;
	/* if(c[0]==d[0]){ */
	/* 	return c[1]-d[1]; */
	/* } else { */
	/* 	return c[0]-d[0]; */
	/* } */
	return c[0]-d[0]?c[0]-d[0]:c[1]-d[1];
}

int cmp2(const void *a,const void *b)
{
	int *c=*(int (*)[2])a;
	int *d=*(int (*)[2])b;
	return c[1]-d[1];
}
int cmp3(const void *a,const void *b)
{
	int *c=*(int (*)[2])a;
	int *d=*(int (*)[2])b;
	/* if(c[0]==d[0]){ */
	/* 	return d[1]-c[1]; */
	/* } else { */
	/* 	return d[0]-c[0]; */
	/* } */
	return d[0]-c[0]?d[0]-c[0]:d[1]-c[1];
}

int cmp4(const void *a,const void *b)
{
	int *c=*(int (*)[2])a;
	int *d=*(int (*)[2])b;
	return d[1]-c[1];
}
	
int main(void)
{
	int n,k1,k2,i,Case=0;
	while(scanf("%d%d%d",&n,&k1,&k2),!(n==0 && k1 == 0 && k2==0)){
		++Case;
		for(i=0;i<n;++i){
			scanf("%d",s[i]);
			s[i][1]=i+1;
		}
		printf("Case %d\n",Case);
		qsort(s,n,sizeof(int [2]),cmp1);
		qsort(s,k1,sizeof(int [2]),cmp2);
		printf("%d",s[0][1]);
		for(i=1;i<k1;++i){
			printf(" %d",s[i][1]);
		}
		puts("");
		qsort(s,n,sizeof(int [2]),cmp3);
		qsort(s,k2,sizeof(int [2]),cmp4);
		printf("%d",s[0][1]);
		for(i=1;i<k2;++i){
			printf(" %d",s[i][1]);
		}
		puts("");
	}
	return 0;
}

		
