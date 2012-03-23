import java.util.*;

class Main
{
    static final int N=5842+1;
    static int []hb;
    public static final int min(int first,int ... rest)
    {
	int min=first;
	for(int i:rest){
	    min=Math.min(min,i);
	}
	return min;
    }
    
    public static void main(String[]args)
    {
	int i,j,a,b,c,d;
	a=b=c=d=1;
	hb=new int[N];
	for(i=0;i<8;++i){
	    hb[i]=i;
	}
	for(i=8;i<N;++i){
	    while(2*hb[a]<=hb[i-1]){
		++a;
	    }
	    while(3*hb[b]<=hb[i-1]){
		++b;
	    }
	    while(5*hb[c]<=hb[i-1]){
		++c;
	    }
	    while(7*hb[d]<=hb[i-1]){
		++d;
	    }
	    hb[i]=min(2*hb[a],3*hb[b],5*hb[c],7*hb[d]);
	}
	Scanner sc=new Scanner(System.in);
	String suf;
	while((i=sc.nextInt())!=0){
	    if(i/10%10==1){
		j=4;
	    }
	    else{
		j=i%10;
	    }
	    switch(j){
	    case 1:
		suf="st";
		break;
	    case 2:
		suf="nd";
		break;
	    case 3:
		suf="rd";
		break;
	    default:
		suf="th";
		break;
	    }

	    System.out.println("The "+i+suf+" humble number is "+hb[i]+".");
	}
    }
}

	    
