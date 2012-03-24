import java.util.*;

class Main
{
    public static final int N=9;
    
    public static void main(String[]args)
    {
	int i;
	int []ar=new int[N];
	long n;
	Scanner sc=new Scanner(System.in);
	while((n=sc.nextLong())!=0){
	    for(i=2,Arrays.fill(ar,0);n!=1;){
		while(n%i==0){
		    ++ar[i];
		    n/=i;
		}
		++i;
	    }
	    for(n=1,i=0;i<ar.length;++i){
		n*=ar[i]+1;
	    }
	    System.out.println(n);
	}
    }
}

	
