import java.util.*;

class Main
{
    public static final int N=20+1,M=1000+1;
    
    public static void main(String []args)
    {
	int c,n,m;
	int i,j,k;
	int max;
	int [][]arr;
	Scanner sc=new Scanner(System.in);
	c=sc.nextInt();
	while(c-->0){
	    n=sc.nextInt();
	    m=sc.nextInt();
	    arr=new int[n+1][m+1];
	    for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
		    arr[i][j]=sc.nextInt();
		}
	    }
	    for(j=m-1;j>=1;--j){
		max=arr[n][j+1];
		for(k=2;j*k<m;++k){
		    max=Math.max(max,arr[n][j*k]);
		}
		arr[n][j]+=max;
	    }
	    for(i=n-1;i>=1;--i){
		arr[i][m]+=arr[i+1][m];
	    }
	    for(i=n-1;i>=1;--i){
		for(j=m-1;j>=1;--j){
		    max=Math.max(arr[i][j+1],arr[i+1][j]);
		    for(k=2;j*k<m;++k){
			max=Math.max(max,arr[i][j*k]);
		    }
		    arr[i][j]+=max;
		}
	    }
	    System.out.println(arr[1][1]);
	}
    }
}

		
