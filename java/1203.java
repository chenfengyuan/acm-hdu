// 1203	I NEED A OFFER
import java.util.*;
class Main
{
    public static final int N=10000+1;
    public static void main(String[]args)
    {
	double []dp=new double[N];
	int n,i,a,j,m;
	double b,min;
	Scanner sc=new Scanner(System.in);
	while(true){
	    n=sc.nextInt();
	    m=sc.nextInt();
	    if(n==0&&m==0)
		break;
	    Arrays.fill(dp,1,n+1,100000000000.0);
	    dp[0]=1.0;
	    min=1.0;
	    for(i=0;i<m;++i){
		a=sc.nextInt();
		b=1.0-sc.nextDouble();
		for(j=n;j>=a;--j){
		    dp[j]=Math.min(dp[j-a]*b,dp[j]);
		    min=Math.min(min,dp[j]);
		}
	    }
	    System.out.printf("%.1f%%%n",(1-min)*100);
	}
    }
}

	    
	    
