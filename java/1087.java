import java.util.*;

class Main
{
    public static final int N=1000;
    public static void main(String[]args)
    {
	long [][]q=new long[2][N];
	int i,j,n;
	long max;
	Scanner sc=new Scanner(System.in);
	while((n=sc.nextInt())!=0){
	    for(i=0;i<n;++i){
		q[0][i]=sc.nextInt();
	    }
	    for(i=0;i<n;++i){
		max=0;
		for(j=0;j<i;++j){
		    if(q[0][j]<q[0][i]&&q[1][j]>max){
			max=q[1][j];
		    }
		}
		q[1][i]=q[0][i]+max;
	    }
	    for(max=0,i=0;i<n;++i){
		max=Math.max(max,q[1][i]);
	    }
	    System.out.println(max);
	}
    }
}

