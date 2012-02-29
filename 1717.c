#include <stdio.h>
#include <string.h>
#include <math.h>
#ifdef ONLINE_JUDGE
#define L "%I64d"
#else
#define L "%lld"
#endif
#define S 128

long long gcd(long long a,long long b)
{
	long long t;
	while(b){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}

int main(void)
{
	long long a,b,an,bn,t,c,p,q;
	char s[S];
    
	scanf(L,&t);
	while(t--){
		/* fgets(s,S,stdin); */
		scanf("%s",s);
		if(s[strlen(s)-1]==')'){
			if(s[2]!='('){
				sscanf(s,"0." L "(" L,&a,&b);
				an=strchr(s,'(')-s-2;
				bn=strlen(s)-4-an;
			} else {
				a=an=0;
				sscanf(s,"0.("L,&b);
				bn=strlen(s)-4;
			}
		} else {
			b=bn=0;
			an=strlen(s)-2;
			sscanf(s,"0." L ,&a);
		}
		/* printf(L "," L "," L "," L"\n",a,an,b,bn); */
		if(bn){
			p=a*pow(10,bn)+b-a;
			q=pow(10,an+bn)-pow(10,an);
		} else {
			p=a;
			q=pow(10,an);
		}
		/* printf(L "," L "\n",p,q); */
		/* if(q==p){ */
		/*     printf("1\n"); */
		/* } else { */
		c=gcd(p,q);
		printf(L "/" L "\n",p/c,q/c);
		/* } */
	}
	return 0;
}
