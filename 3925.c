#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define LLMAX 9223372036854775807ll
#define A_MAX 100
#define B_MAX 7
#define ONLINE
char a[A_MAX+3];
char b[B_MAX+2];
char a_r[A_MAX+3];
char b_r[B_MAX+2];
long long least(char *a,char *b_str);

char * reverse(const char * old,char *new)
{
	int i,j,l;
	l=strlen(old);
	for(i=0,j=l-1;j>=0;j--,i++){
		new[i]=old[j];
	}
	new[i]=0;
	return new;
}

char * strrstr(char * a,char * b)
{
	int l;
	char *r;
	reverse(a,a_r);
	reverse(b,b_r);
	l=strlen(a);
	r=strstr(a_r,b_r);
	if(r==NULL){
		return NULL;
	} else {
		return a+l-1-(r-a_r);
	}
}
char * minus_one(char * s)
{
	int i,l=strlen(s);
	for(i=l-1;i>=0;i--){
		if(s[i]=='0'){
			s[i]='9';
		} else {
			s[i]-=1;
			break;
		}
	}
	return s;
}
char * plus_one(char *s)
{
	int i,l=strlen(s);
	for(i=l-1;i>=0;i--){
		if(s[i]=='9'){
			s[i]='0';
		} else {
			s[i]+=1;
			break;
		}
	}
	return s;
}

long long en(int n)
{
	return pow(10,n);
}

long long find(char * a_str,char *b_str)
{
	int lb=strlen(b_str);
	int la=strlen(a_str);
	char *f;
	int i,l;
	long long a;
	if(la<=lb)
		return LLMAX;
	minus_one(b_str);
	f=strrstr(a_str,b_str);
	plus_one(b_str);
	if(f==NULL)
		return LLMAX;
	l=strlen(f);
	if(l<=lb){
		return en(l-1)*(*f-'0'+1)-strtol(f,NULL,0);
	}
	for(i=strlen(++f);i>=2 && *f == '9';i--,f++)
		;
#ifndef ONLINE
	printf("[%d],",i);
#endif
	if(i<=lb+2){
		a=en(i)-strtol(f,NULL,10);
	} else {
		a=LLMAX;
	}
	return a;
}

int min_int(int a,int b)
{
	return a>b?b:a;
}
long long min_ll(long long a,long long b)
{
	return a>b?b:a;
}


int nth(long long i)
{
	if(i==0)
		return 1;
	return 1+floor(log10(i));
}

long long least(char *a,char *b_str)
{
	long long b=strtol(b_str,NULL,10);
	int bits=nth(b),i;
	long long max=en(bits),min=LLMAX;
	long long c,t;
	c=strtol(a+strlen(a)-min_int(bits*2,strlen(a)),NULL,10);
	for(i=0;i<=bits;i++){
		t=c%max;
		/* printf("%lld,%lld,%lld\n",c,b,max); */
		
		if(t>b){
			t=max+b-t;
		} else {
			t=b-t;
		}
		if(t<min){
			min=t;
		}
		b*=10;
		max*=10;
	}
	return min;
}

int main()
{
	int n,i;
#ifndef ONLINE
   freopen("3925.in", "r", stdin);
#endif	
	scanf("%d",&n);
	*a='0';
	for(i=1;i<=n;i++){
		scanf("%s%s",a+1,b);
		printf("Case #%d: ",i);
		if(strstr(a+1,b)){
			printf("0\n");
		} else {
#ifndef ONLINE
			printf("%lld,%lld\n",find(a,b),least(a+1,b));
			/* printf(",%s,%s\n",a+1,b); */
#else
			printf("%lld\n",min_ll(find(a,b),least(a+1,b)));
#endif
		}
		fflush(stdout);
	}
	return 0;
}
