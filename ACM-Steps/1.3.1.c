#include <stdio.h>
#include <stdlib.h>

#define N 2000
int t[N];
int k[N];

int cmp(const void* a,const void *b)
{
	return *(int *)a-*(int *)b;
}

int main(void)
{
	int n,i,j,w,l,e,e_n;
	while(~scanf("%d",&n) && (n != 0)){
		for(i=0;i<n;++i){
			scanf("%d",t+i);
		}
		qsort(t,n,sizeof(int),cmp);
		for(i=0;i<n;++i){
			scanf("%d",k+i);
		}
		qsort(k,n,sizeof(int),cmp);
		w=l=i=j=e_n=0;
		while((i<n)&&(j<n)){
			if(t[i]>k[j]){
				++w;
				++i;
				++j;
			}
			else if(t[i]==k[j]){
				if(e_n<=0){
					e_n=1;
					e=t[i];
					++i;
					++j;
				}
				else if(t[i]==e){
					++e_n;
					++i;
					++j;
				}
				else if(t[i]>e){
					--e_n;
					++i;
				}
			} else {
				if((e_n>0) && (t[i]>e)){
					--e_n;
					++i;
				} else {
					++i;
					++l;
				}
			}
		}
		printf("%d\n",200*(w-l));
	}
	return 0;
}

	
