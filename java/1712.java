// 1712 ACboy needs your help
import java.util.*;

class Main
{
    public static final int M;
    static
    {
	M=200;
    }
    public static void main(String[]args)
    {
	int n,m;
	int []v=new int[M];
	int []dp2=new int[M];
	int i,j,k;
	Scanner sc=new Scanner(System.in);
	while(true){
	    n=sc.nextInt();
	    m=sc.nextInt();
	    if(n==0 && m==0)
		break;
	    Arrays.fill(dp2,1,m+1,0);
	    for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
		    v[j]=sc.nextInt();
		}
		for(j=m;j>=1;--j){
		    for(k=1;k<=j;++k){
			dp2[j]=Math.max(dp2[j],dp2[j-k]+v[k]);
		    }
		}
	    }
	    System.out.println(dp2[m]);
	}
    }
}
