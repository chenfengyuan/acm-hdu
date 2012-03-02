/* http://xuyemin520.is-programmer.com/posts/26216.html */
#include <stdio.h>
#include <string.h>

int arr[3][64];

int main(void)
{
	int m,n,i,j,t;
	int *a,*b,*c,*tmp;
	int correct;
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(arr,0,sizeof(arr));
		for(i=0;i<3;++i){
			scanf("%d",&m);
			for(j=0;j<m;++j)
				scanf("%d",arr[i]+j);
		}

		/* for(i=0;i<3;++i){ */
		/* 	for(j=0;arr[i][j];++j) */
		/* 		printf("%d ",arr[i][j]); */
		/* 	printf("\n"); */
		/* } */
		a=arr[0];
		b=arr[1];
		c=arr[2];
		correct=1;
		while(n>0){
			if(*b==n){
				correct=0;
				break;
			}
			else if(*a==n){
				++a;
				--n;
				tmp=b;
				b=c;
				c=tmp;
			}
			else if(*c==n){
				++c;
				--n;
				tmp=a;
				a=b;
				b=tmp;
			} else {
				correct=0;
				break;
			}
		}
		if(correct)
			puts("true");
		else
			puts("false");
	}
	return 0;
}

