#include <stdio.h>
#include <string.h>
#define C 26 			/* chars */
#define V 50			/* value */
#define COL ((V)+1)		/* elements per row */
#define MIN(a,b) ((a)>(b)?(b):(a))
int main()
{
	int c[C+1]={0},a[(C+1)*(V+1)],n,i,j,k;
	scanf("%d",&n);
	while(n--){
		memset(a,0,(C+1)*(V+1)*sizeof(int));
		for(i=1;i<=C;i++){
			scanf("%d",c+i);
		}
		for(i=1;c[i]==0;i++)
			;
		for(k=1;k<=50;k++)
			a[COL*i+k]=MIN(k/i,c[i]);
		for(i++;i<=C;i++){
			for(k=1;k<=50;k++){
				a[i*COL+k]=a[(i-1)*COL+k];
				for(j=1;j<=c[i] && i*j<=k;j++)
					a[i*COL+k]+=1+a[(i-1)*COL+(k-i*j)];
			}
		}
		printf("%d\n",a[COL*C+V]);
	}
}

		
