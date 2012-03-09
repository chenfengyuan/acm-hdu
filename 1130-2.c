#include <stdio.h>
#include <string.h>

#define BIGNUM 100
#define N 101
typedef struct
{
	int n[BIGNUM];
	int l;
} bignum;

bignum mul(bignum a,bignum b)
{
	int i,j,t;
	bignum c;
	memset(&c,0,sizeof(bignum));
	for(i=0;i<a.l;++i){
		for(j=0;j<b.l;++j){
			c.n[j+i]+=a.n[i]*b.n[j];
		}
	}
	t=0;
	for(i=0;i<a.l+b.l-1;++i){
		t+=c.n[i];
		c.n[i]=t%10000;
		t/=10000;
	}
	if(t>0){
		c.n[i]=t;
		c.l=a.l+b.l;
	} else {
		c.l=a.l+b.l-1;
	}
	return c;
}
bignum plus(bignum a,bignum b)
{
	bignum c;
	int i,t;
	memset(&c,0,sizeof(c));
	for(i=0;i<a.l && i<b.l;++i){
		c.n[i]=a.n[i]+b.n[i];
	}
	if(a.l>b.l){
		for(;i<a.l;++i){
			c.n[i]=a.n[i];
		}
		c.l=a.l;
	} else {
		for(;i<b.l;++i){
			c.n[i]=b.n[i];
		}
		c.l=b.l;
	}
	t=0;
	for(i=0;i<c.l;++i){
		t+=c.n[i];
		c.n[i]=t%10000;
		t/=10000;
	}
	if(t>0){
		c.n[i]=t;
		++c.l;
	}
	return c;
}

char * print_bignum(char *str,bignum a)
{
	int i,j;
	j=sprintf(str,"%d",a.n[a.l-1]);
	for(i=a.l-2;i>=0;--i,j+=4){
		sprintf(str+j,"%04d",a.n[i]);
	}
	return str;
}

	
bignum b[N];

int main(void)
{
	int i,j;
	char str[BIGNUM*4+1];
	b[1].n[0]=1;
	b[1].l=1;
	b[0].n[0]=1;
	b[0].l=1;
	for(i=2;i<N;++i){
		for(j=0;j<=i-1;++j){
			b[i]=plus(b[i],mul(b[j],b[i-1-j]));
		}
	}
	while(~scanf("%d",&i)){
		printf("%s\n",print_bignum(str,b[i]));
	}
	
	/* bignum a={.n={58786},.l=1}; */
	/* bignum b={.n={2},.l=1}; */
	/* mul(a,b); */
	return 0;
}

