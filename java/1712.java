import java.util.*;

class Main
{
    public static final int N,M;
    static
    {
	N=M=200;
    }
    public static int max(int first,int ... all)
    {
	int max=first;
	for(int i:all){
	    max=Math.max(max,i);
	}
	return max;
    }
    public static void main(String[]args)
    {
	int n,m;
	int [][]dp1=new int[N][M];
	int [][]dp2=new int[N][M];
	int i,j,k;
	Scanner sc=new Scanner(System.in);
	for(j=0;j<M;++j){
	    dp2[0][j]=dp1[0][j]=0;
	}
	for(i=0;i<N;++i){
	    dp2[i][0]=dp1[i][0]=0;
	}
	while(true){
	    n=sc.nextInt();
	    m=sc.nextInt();
	    if(n==0 && m==0)
		break;
	    for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
		    dp1[i][j]=sc.nextInt();
		}
	    }
	    // for(i=0;i<=n;++i){
	    // 	for(j=0;j<=m;++j){
	    // 	    System.out.print(dp1[i][j]+" ");
	    // 	}
	    // 	System.out.println("");
	    // }
	    for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
		    dp2[i][j]=dp2[i-1][j];
		    for(k=1;k<=j;++k){
			dp2[i][j]=Math.max(dp2[i][j],dp2[i-1][j-k]+dp1[i][k]);
		    }
		}
	    }
	    // for(i=0;i<=n;++i){
	    // 	for(j=0;j<=m;++j){
	    // 	    System.out.print(dp2[i][j]+" ");
	    // 	}
	    // 	System.out.println("");
	    // }
	    System.out.println(dp2[n][m]);
	}
    }
}
