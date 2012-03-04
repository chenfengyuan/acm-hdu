#include <stdio.h>
#include <string.h>

#define N 1010

char a[N],b[N];
int c[N];

 int main(void)
{
	int test,la,lb,i,n,t,j;
	char *ap,*bp;
	scanf("%d",&test);
	for(j=1;j<=test;++j){
		scanf("%s%s",a,b);
		la=strlen(a);
		lb=strlen(b);
		if(la>lb){
			t=la;
			la=lb;
			lb=t;
			ap=b;
			bp=a;
		} else {
			ap=a;
			bp=b;
		}
		t=ap[la-1]-'0'+bp[lb-1]-'0';
		c[0]=t%10;
		c[1]=t/10;
		for(i=1,n=1;i<la;++i,++n){
			t=ap[la-i-1]-'0'+bp[lb-i-1]-'0'+c[i];
			c[i]=t%10;
			c[i+1]=t/10;
		}
		while(i<lb){
			++n;
			t=bp[lb-i-1]-'0'+c[i];
			c[i]=t%10;
			c[i+1]=t/10;
			++i;
		}
		printf("Case %d:\n",j);
		printf("%s + %s = ",a,b);
		if(c[n])
			printf("%d",c[n]);
		for(i=n-1;i>=0;--i){
			printf("%d",c[i]);
		}
		printf("\n");
		if(j<test)
			printf("\n");
	}
	return 0;
}

