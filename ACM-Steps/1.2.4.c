#include <stdio.h>

int main(void)
{
	int c;
	for(;(c=getchar())!='#';){
		switch(c){
		case ' ':
		case '!':
		case '$':
		case '%':
		case '(':
		case ')':
		case '*':
			printf("%%%02x",c);
			break;
		default:
			putchar(c);
		}
	}
	return 0;
}
