#include <stdio.h>
int main()
{
        int c,n,i,j,a,b,k;
	int arr[5050+1];

	
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		for(i=1;i<=(1+n)*n/2;i++)
			scanf("%d",arr+i);
		for(a=i-2*n+1,b=i-n,i=n-1;i>0;a=a-i+1,b=b-i,i--){
			/* for(k=0;k<=(n+1)*n/2;k++)printf("%d ",arr[k]);printf("\n"); */
			for(j=0;j<i;j++){
				if(arr[b+j]>arr[b+j+1]){
					arr[a+j]+=arr[b+j];
				} else {
					arr[a+j]+=arr[b+j+1];
				}
			}
		}
		printf("%d\n",arr[1]);
	}
	return 0;
}

				
		
}
	return 0;
}

				
		


		
