#include <stdio.h>
#include <stdlib.h>
#define N 11
#define MAX(a,b) ((a)>(b)?(a):(b))

int a[100000][11][2];
int c[100000];
int d[100000];

int b[11][2];

int compare(const void *a,const void *b)
{
	int *c=*(int (*)[2])a;
	int *d=*(int (*)[2])b;
	/* return **(int (*)[2])a-**(int (*)[2])b; */
	return c[0]*12+d[1]-d[0]*12-c[1];
}

int main(void)
{
	int n,w,i,j=0,t,n_i;
	double sum;
	while((~scanf("%d%d",&n,&w))&& !(n==0 && w==0)){
		n_i=0;
		for(i=0;i<n;++i){
			scanf("%d",&t);
			b[t/w][0]=++a[j][t/w][0];
			/* max=MAX(max,a[j][t/w][0]); */
			n_i=MAX(n_i,t/w);
		}
		c[j]=n_i++;
		for(i=0;i<n_i;++i){
			b[i][1]=i;
		}
		qsort(b,n_i,sizeof(b[11]),compare);
		for(i=0;i<n_i;++i){
			a[j][b[i][1]][1]=i;
		}
		d[j]=b[n_i-1][0];
		/* for(i=0;i<n_i;++i){ */
		/* 	printf("%d,%d ",a[j][i][0],a[j][i][1]); */
		/* } */
		j++;
	}
	n=j;
	for(j=0;j<n;++j){
		sum=0.01;
		for(i=0;i<=c[j];++i){
			sum+=1.0/d[j]*a[j][i][0]*(c[j]-i)/c[j];
			/* sum+=1.0/max*a[j][i][0]*(c[j]-i)/d[j]; */
		}
		printf("%.6lf\n",sum);
	}
	return 0;
}
	
	
	
			
