#include <stdio.h>

int xor_a2b(int a,int b)
{
	int xor=0;
	int i;
	for(i=a;i<=b;++i){
		xor^=i;
	}
	return xor;
}
int xor_random_seq(int step,int mod)
{
	int i;
	int xor=0;
	int seed=0;
	for(i=0;i<mod;++i){
		printf("%d ",seed);
		xor^=seed;
		seed=(seed+step)%mod;
	}
	return xor;
}

int ifgood(int step,int mod)
{
	int a2b=xor_a2b(0,mod-1);
	int random_seq=xor_random_seq(step,mod);
	/* printf("%d,%d",a2b,random_seq); */
	if(a2b==random_seq)
		return 1;
	else
		return 0;
}

int ifgood2(int step,int mod)
{
	int i;
	int seed=0;
	for(i=1;i<mod;++i){
		seed=(seed+step)%mod;
		/* printf("%d ",seed); */
		if(seed==0)
			break;
	}
	if(i==mod)
		return 1;
	else
		return 0;
}
void myprint(int step,int mod)
{
	printf("%10d%10d    %-s\n",step,mod,
	       ifgood2(step,mod)?"Good Choice":"Bad Choice");
}

int main(void)
{
	int step=0,mod=0;
	int first=1;
	while(scanf("%d %d",&step,&mod)!=EOF){
		/* if(first!=1){ */
		/* 	printf("\n"); */
		/* } else { */
		/* 	first=0; */
		/* } */
		myprint(step,mod);
		printf("\n");
		
	}
	return 0;
}
