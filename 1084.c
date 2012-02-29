#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 128
#define STR 16
#define P 8
int stu[N][2];
int r[N];
int p[P];

char str[STR];

int cmp(const void *a,const void *b)
{
	return (*(int (*)[2])a)[1]-(*(int (*)[2])b)[1];
}

int main(void)
{
	int i,n,j,k,b;
	while(~scanf("%d",&n) && (n != -1)){
		getchar();
		memset(p,0,P*sizeof(int));
		for(i=0;i<n;++i){
			fgets(str,STR,stdin);
			/* 5 06:30:17 */
			/* 0123456789a */
			stu[i][0]=i;
			stu[i][1]=100000*(*str-'0')-(str[8]*10+str[9]+60*(str[5]*10+str[6]+60*(str[2]*10+str[3])));
			++p[*str-'0'];
		}
		qsort(stu,n,sizeof(int [2]),cmp);
		/* for(i=0;i<n;++i){ */
		/* 	printf("%d,%d\n",stu[i][0],stu[i][1]); */
		/* } */
		k=p[0];
		b=60;
		for(i=0;i<p[0];++i){
			stu[i][1]=50;
		}
		for(i=1;i<5;k+=p[i],++i){
			for(j=0;j<(p[i]+1)/2;++j){
				stu[j+k][1]=b;
			}
			b+=5;
			for(;j<p[i];++j){
				stu[j+k][1]=b;
			}
			b+=5;
		}
		for(i=0;i<p[5];++i){
			stu[k+i][1]=100;
		}
		for(i=0;i<n;++i){
			r[stu[i][0]]=stu[i][1];
		}
		for(i=0;i<n;++i){
			printf("%d\n",r[i]);
		}
		printf("\n");
	}
	return 0;
}
