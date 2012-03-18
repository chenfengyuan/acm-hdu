/* 1131 Count the Trees */
#include <stdio.h>
#include <string.h>

#define N 101

#define BIGNUM 100
#define BIGNUM_STR (((BIGNUM)<<2)+1)
typedef struct
{
    int n[BIGNUM];
    int l;
} bignum;

bignum bignum_init(int n)
{
    bignum num;
    num.n[0]=n;
    num.l=1;
    return num;
}
bignum mul(bignum a,bignum b)
{
    int i,j,t;
    bignum c;
    memset(&c,0,sizeof(c));
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
bignum add(bignum a,bignum b)
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

char * bignum_string(char *str,bignum a)
{
    int i,j;
    j=sprintf(str,"%d",a.n[a.l-1]);
    for(i=a.l-2;i>=0;--i,j+=4){
        sprintf(str+j,"%04d",a.n[i]);
    }
    return str;
}



bignum dp[N];
bignum fac[N];
bignum p[N];

void cal_fac(void)
{
    int i;
    fac[0]=bignum_init(1);
    fac[1]=bignum_init(1);
    for(i=2;i<N;++i){
        fac[i]=mul(fac[i-1],bignum_init(i));
    }
}

void cal_dp(void)
{
    int i,j;
    dp[0]=bignum_init(1);
    dp[1]=bignum_init(1);
    for(i=2;i<N;++i){
        dp[i]=bignum_init(0);
        for(j=0;j<i;++j){
            dp[i]=add(dp[i],mul(dp[j],dp[i-j-1]));
        }
    }
}
void cal_p(void)
{
    int i;
    for(i=0;i<N;++i){
        p[i]=mul(fac[i],dp[i]);
    }
}

int main(void)
{
    int i;
    char bstr[BIGNUM_STR];
    cal_dp();
    cal_fac();
    cal_p();
    /* for(i=0;i<N;++i){ */
    /*     printf("%d\t%s\n",i,bignum_string(bstr,dp[i])); */
    /* } */
    /* puts(""); */
    /* for(i=0;i<N;++i){ */
    /*     printf("%d\t%s\n",i,bignum_string(bstr,fac[i])); */
    /* } */
    /* puts(""); */
    /* for(i=0;i<N;++i){ */
    /*     printf("%d\t%d\t%s\n",i,strlen(bignum_string(bstr,p[i])),bignum_string(bstr,p[i])); */
    /* } */
    while(scanf("%d",&i),i){
        puts(bignum_string(bstr,p[i]));
    }
    return 0;
}
