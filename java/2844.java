import java.util.*;
class Main
{
    public static final int M=100100,N=110;
    public static void onepack(int []dp,int a,int m)
    {
	int i;
	for(i=m;i>=a;--i){
	    if(dp[i-a]>0 && dp[i]==0){
		dp[i]=++count;
	    }
	}
    }
    public static int count;
    
    public static void main(String[]args)
    {
	int n,m=0,a,c,i,j;
	int []dp=new int[M];
	int [][]coins=new int[N][2];
	Scanner sc=new Scanner(System.in);
	n=sc.nextInt();
	m=sc.nextInt();
	while(!(n==0 && m==0)){
	    m=Math.max(0,m);
	    Arrays.fill(dp,1,m+1,0);
	    dp[0]=1;
	    count=0;
	    for(i=0;i<n;++i){
		coins[i][0]=sc.nextInt();
	    }
	    for(i=0;i<n;++i){
		coins[i][1]=sc.nextInt();
	    }
	    for(i=0;i<n;++i){
		a=coins[i][0];
		c=coins[i][1];
		j=1;
		while(j<=c){
		    onepack(dp,j*a,m);
		    c-=j;
		    j*=2;
		    // System.out.println(Arrays.toString(dp));
		}
		if(c>0){
		    onepack(dp,c*a,m);
		}
		// System.out.println(Arrays.toString(dp));
	    }
	    n=sc.nextInt();
	    m=sc.nextInt();
	    System.out.println(count);
	}
    }
}

		
