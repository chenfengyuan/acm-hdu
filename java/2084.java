import java.util.*;

class Main
{
    public static final int N=100;
    public static void main(String[]args)
    {
	int c,n,i,j,k1,k2;
	int [][]arr=new int[2][N];
	Scanner sc=new Scanner(System.in);
	c=sc.nextInt();
	while(c-->0){
	    n=sc.nextInt();
	    arr[0][0]=sc.nextInt();
	    k1=1;
	    k2=0;
	    for(i=2;i<=n;++i){
		arr[k1][0]=arr[k2][0]+sc.nextInt();
		for(j=1;j<i-1;++j){
		    arr[k1][j]=Math.max(arr[k2][j-1],arr[k2][j])+sc.nextInt();
		}
		arr[k1][j]=arr[k2][j-1]+sc.nextInt();
		k1=k2;
		k2=(k1+1)%2;
	    }
	    i=0;
	    for(j=0;j<n;++j){
		if(arr[k2][j]>i){
		    i=arr[k2][j];
		}
	    }
	    System.out.println(i);
	}
    }
}

		
