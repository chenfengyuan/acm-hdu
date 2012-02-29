#include <stdio.h>

char s[52];

int main(void)
{
	int i,n,j;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;++i){
		fgets(s,52,stdin);
		j=0;
		while(s[j]!='\n'){
			switch(s[j]){
			case 'Z':
				s[j]='A';
				break;
			default:
				++s[j];
				break;
			}
			++j;
		}
		printf("String #%d\n",i);
		fputs(s,stdout);
		putchar('\n');
	}
	return 0;
}

				
