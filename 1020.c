#include <stdio.h>
#define N 10001

char str[N];

int main(void)
{
	int i,n,j;
	scanf("%d\n",&n);
	while(n--){
		gets(str);
		for(i=0;str[i]!=0;i=j){
			for(j=i+1;str[j]!=0 && str[j]==str[i];++j)
				;
			if(i+1==j)
				putchar(str[i]);
			else
				printf("%d%c",j-i,str[i]);
		}
		putchar('\n');
	}
	return 0;
}

