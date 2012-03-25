import java.util.*;

class Main
{
    public static final int N=10000+1;
    
    public static void main(String[]args)
    {
	int []dp=new int[N];
	int t,f,p,w,i=0,n;
	Scanner sc=new Scanner(System.in);
	t=sc.nextInt();
	while(t-->0){
	    f=-(sc.nextInt()-sc.nextInt());
	    Arrays.fill(dp,1,f+1,Integer.MAX_VALUE/10);
	    n=sc.nextInt();
	    dp[0]=0;
	    while(n-->0){
		p=sc.nextInt();
		w=sc.nextInt();
		for(i=0;i+w<=f;++i){
		    dp[i+w]=Math.min(dp[i+w],dp[i]+p);
		}
	    }
	    if(dp[f]==Integer.MAX_VALUE/10){
		System.out.println("This is impossible.");
	    }
	    else{
		System.out.println("The minimum amount of money in the piggy-bank is "+dp[f]+".");
	    }
	}
    }
}

	    
