#include <stdio.h>
#include <string.h>
#define N 100
char idf[16],idl[16],idt[16];
char f[9],ft[9];
char l[9],lt[9];
char temp[N];

void exact(void)
{
	char *s;
	s=strchr(temp,' ');
	strncpy(idt,temp,s-temp);
	idt[s-temp]=0;
	strncpy(ft,s+1,8);
	strncpy(lt,s+10,8);
}

	
int main(void)
{
	int n,m;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		getchar();
		--m;
		fgets(temp,N,stdin);
		exact();
		strcpy(idf,idt);
		strcpy(idl,idt);
		strcpy(f,ft);
		strcpy(l,lt);
		while(m--){
			fgets(temp,N,stdin);
			exact();
			if(strcmp(ft,f)<0){
				strcpy(idf,idt);
				strcpy(f,ft);
			}
			if(strcmp(lt,l)>0){
				strcpy(idl,idt);
				strcpy(l,lt);
			}
		}
		printf("%s %s\n",idf,idl);
	}
	return 0;
}

	
