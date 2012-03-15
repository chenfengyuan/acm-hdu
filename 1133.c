#include <stdio.h>
#include <string.h>
#define N 101
#define BIGNUM 100

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

    
bignum fac[N];
bignum p[N][N];

void cal_p(void)
{
	int i,j;
	for(i=0;i<N;++i){
		for(j=0;j<N;++j){
			p[i][j].n[0]=0;
			p[i][j].l=1;
		}
	}
	for(i=0;i<N;++i){
		p[i][0].n[0]=1;
		p[i][0].l=1;
	}
	for(i=1;i<N;++i){
		for(j=1;j<=i;++j){
			p[i][j]=plus(p[i-1][j],p[i][j-1]);
		}
	}
}

void cal_fac(void)
{
	int i;
	fac[0].n[0]=1;
	fac[0].l=1;
	for(i=1;i<N;++i){
		fac[i].n[0]=i;
		fac[i].l=1;
	}
	for(i=2;i<N;++i){
		fac[i]=mul(fac[i-1],fac[i]);
	}
}
        
int main(void)
{
	int i,j,n;
	char str[1000];char str3[1000];char str2[1000];
	cal_p();
	cal_fac();
	/* for(i=0;i<N;++i){ */
	/*     for(j=0;j<N;++j){ */
	/*         printf("%s ",print_bignum(str,p[i][j])); */
	/*     } */
	/*     printf("\n"); */
	/* } */
	/* for(i=0;i<N;++i){ */
	/*     printf("%d\t%s\n",i,print_bignum(str,fac[i])); */
	/* } */
	n=0;
	while(scanf("%d%d",&i,&j),i||j){
		++n;
		if(i>=j){
			printf("Test #%d:\n%s\n",n,print_bignum(str2,mul(mul(fac[i],fac[j]),p[i][j])));
		} else {
			printf("Test #%d:\n0\n",n);
		}
	}
	return 0;
}

