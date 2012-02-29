#include <stdio.h>
#include <string.h>

char s[100003];

int main(void)
{
	int alphabet[26];
	int i;
	while(fgets(s,100003,stdin)!=NULL){
		memset(alphabet,0,26*sizeof(int));
		for(i=0;s[i]!='\n';++i){
			if((s[i]>='a')&&(s[i]<='z')){
				++alphabet[s[i]-'a'];
			}
		}
		for(i='a';i<='z';++i){
			printf("%c:%d\n",i,alphabet[i-'a']);
		}
		printf("\n");
	}
	return 0;
}

