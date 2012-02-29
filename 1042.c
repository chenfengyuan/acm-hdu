#include <stdio.h>
#define M 10000
#define MB 4
struct BIGNUM{
	int arr[9000];
	int msb;
}bignum;

void init()
{
	bignum.msb=0;
	bignum.arr[0]=1;
}

void multipy(int n)
{
	int i,j,*t=bignum.arr,msb=bignum.msb,tmp;
	
	for(i=0,j=0;i<=msb;i++,t++){
		tmp=(*t*n+j);
		*t=tmp%M;
		j=tmp/M;
	}
	if(j>0){
		*t=j;
		bignum.msb++;
	}
}
void bprint()
{
	int i,*n;
	i=bignum.msb;
	n=bignum.arr+i;
	printf("%d",*n);
	for(n--,i--;i>=0;i--,n--){
		printf("%0*d",MB,*n);
	}
	printf("\n");
}

		
int main()
{
	int i,n;
	while(scanf("%d",&n)!=EOF){
		init();
		for(i=1;i<=n;i++){
			multipy(i);
		}
		bprint();
	}
	return 0;
}
