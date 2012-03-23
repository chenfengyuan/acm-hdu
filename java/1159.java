import java.util.*;
import static java.lang.System.out;

class Main
{
    public static void main(String []args)
    {
	String stra,strb;
	int i,j;
	int [][]c;
	Scanner sc=new Scanner(System.in);
	while(sc.hasNext()){
	    stra=sc.next();
	    strb=sc.next();
	    c=new int[stra.length()+1][strb.length()+1];
	    for(i=0;i<c.length;++i){
		c[i][0]=0;
	    }
	    for(j=0;j<c[0].length;++j){
		c[0][j]=0;
	    }
	    for(i=0;i<stra.length();++i){
		for(j=0;j<strb.length();++j){
		    if(stra.charAt(i)==strb.charAt(j)){
			c[i+1][j+1]=1+c[i][j];
		    } else {
			c[i+1][j+1]=Math.max(c[i+1][j],c[i][j+1]);
		    }
		}
	    }
	    out.println(c[i][j]);
	}
    }
}
