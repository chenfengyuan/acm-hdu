#include <stdio.h>
#define N 1024

int  arr[N]={1,1};

int main(void)
{
	int a,b,n,i,j;
	while(~scanf("%d%d%d",&a,&b,&n) && ! (a==0 && b ==0 && n == 0)){
		--n;
		if(n<2){
			printf("1\n");
			continue;
		}
		arr[2]=(a*arr[1]+b*arr[0])%7;
		for(i=3;i<=n;++i){
			arr[i]=(a*arr[i-1]+b*arr[i-2])%7;
			for(j=0;j<i-2;++j){
				if(arr[j]==arr[i-1] && arr[j+1]==arr[i])
					goto F;
			}
		}
	F:
		if(i>n){
			printf("%d\n",arr[n]);
		} else {
			printf("%d\n",arr[(n-j)%(i-1-j)+j]);
		}
	}
	return 0;
}

