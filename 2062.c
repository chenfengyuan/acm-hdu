#include <stdio.h>

#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define N 20
long long s[N]={1,4,15,64,325,1956,13699,109600,986409,9864100,108505111,1302061344,16926797485,236975164804,3554627472075,56874039553216,966858672404689,17403456103284420,330665665962403999,6613313319248080000};
int a[N];

int main(void)
{
	int n,i,j;
	long long m;
	while(~scanf("%d" LL,&n,&m)){
		for(i=0;i<N;++i)
			a[i]=1;
		while(n>1){
			for(i=0,j=(m-1)/(s[n-2]+1);j>-1;++i)
				if(a[i]==1)
					--j;
			m=(m-1)%(s[n-2]+1);
			--n;
			if(m==0){
				printf("%d\n",i);
				break;
			} else {
				printf("%d ",i);
				a[i-1]=0;
			}
		}
		if(m!=0){
			for(i=0;a[i]==0;++i)
				;
			printf("%d\n",i+1);
		}
	}
	return 0;
}

