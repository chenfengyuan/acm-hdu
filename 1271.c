#include <stdio.h>
#include <stdlib.h>
#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif
#define N 30
long long n[N];
int cmp(const void *a,const void *b)
{
	return *(long long *)a-*(long long *)b;
}

int main(void)
{
	long long a,b,i,a_n,base;
	/* A = a+b*10^k+c*10^(k+1) */
	/* B = a+c*k */
	/* N = 2*a+(b+11c)*10^k */
	while(~scanf(LL,&a) && (a != 0)){
		for(a_n=0,base=1;base<=a;base*=10){
			b=a/base;
			/* printf("[%d,%d,%d] ",b,a%base,base); */
			if((b%11<10) && ((a%base)%2==0)){
				n[a_n++]=a%base/2+base*(b%11+b/11*10);
			}
			if(b>1){
				--b;
				if((b%11<10) && (a%base+base)%2==0){
					n[a_n++]=(a%base+base)/2+base*(b%11+b/11*10);
				}
			}
		}
		if(a_n==0){
			printf("No solution.\n");
		} else {
			qsort(n,a_n,sizeof(long long),cmp);
			printf(LL,n[0]);
			for(i=1;i<a_n;++i){
				if(n[i]!=n[i-1]){
					printf(" " LL,n[i]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

