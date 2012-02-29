#include <stdio.h>
#include <string.h>

#define N 101
int a[N];

int main(void)
{
	int id,m,idt,r,i;
	while(~scanf("%d",&id)){
		memset(a,0,sizeof(int)*N);
		while(~scanf("%d%d",&idt,&i) && (idt != 0 && i != 0)){
			++a[i];
			if(idt==id){
				m=i;
			}
		}
		r=1;
		for(i=N-1;i>m;--i){
			r+=a[i];
		}
		printf("%d\n",r);
	}
	return 0;
}
