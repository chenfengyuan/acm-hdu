// 1864 最大报销额
import java.util.*;

class Main
{
    public static final int N=31;
    public static final int G=100;
    public static final int Q=40000*G;
    public static final int S=600*G,T=G*1000;
    
    public static void main(String[]args)
    {
	int []arr=new int[N];
	int []dp=new int[Q];
	int a,b,c,q,k,m,n,i,j,max;
	boolean g;
	
	Scanner sc=new Scanner(System.in);
	while(true){
	    q=(int)(sc.nextDouble()*G);
	    if(q>=Q){
		while(true);
	    }
	    n=sc.nextInt();
	    if(n==0){
		break;
	    }
	    k=0;
	    for(i=0;i<n;++i){
		m=sc.nextInt();
		a=b=c=0;
		g=true;
		for(j=0;j<m;++j){
		    switch(sc.findInLine("[A-Z]:").charAt(0)){
		    case 'A':
		    	a+=(int)(sc.nextDouble()*G);
		    	if(a>S){
		    	    g=false;
		    	}
		    	break;
		    case 'B':
		    	b+=(int)(sc.nextDouble()*G);
		    	if(b>S){
		    	    g=false;
		    	}
		    	break;
		    case 'C':
		    	c+=(int)(sc.nextDouble()*G);
		    	if(c>S){
		    	    g=false;
		    	}
		    	break;
		    default:
			sc.nextDouble();
		    	g=false;
			break;
		    }
		}
		if(g&&a+b+c<=T){
		    arr[k++]=a+b+c;
		}
	    }
	    for(i=1;i<=q;++i){
		dp[i]=0;
	    }
	    dp[0]=1;
	    max=0;
	    for(i=0;i<k;++i){
		for(j=q;j>=arr[i];--j){
		    if(dp[j-arr[i]]==1){
			dp[j]=1;
			max=Math.max(max,j);
		    }
		}
	    }
	    System.out.printf("%.2f%n",(double)max/G);
	}
    }
}

