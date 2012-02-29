#ifdef ONLINE_JUDGE
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#include <stdio.h>
#include <string.h>

char s[1000];

int main(void)
{
	long long sum,t;
	int n,b;
	int i;
	while(~scanf("%d",&n)){
		sum=0;
		getchar();
		while(n--){
			t=0;
			fgets(s,1000,stdin);
			if(s[strlen(s)-1]=='\n'){
				b=s[strlen(s)-3]-'0';
			} else {
				b=s[strlen(s)-2]-'0';
			}
			
			if(b==0)
				b=10;
			for(i=0;s[i]!='(';++i)
				t=t*b+s[i]-'0';
			sum+=t;
		}
		printf(LL "\n",sum);
	}
	return 0;
}
