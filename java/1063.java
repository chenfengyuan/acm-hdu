import java.util.*;
import java.math.*;

class Main
{
    public static void main(String[]args)
    {
	BigDecimal b,r;
	int p;
	Scanner sc=new Scanner(System.in);
	while(sc.hasNext()){
	    b=sc.nextBigDecimal();
	    p=sc.nextInt();
	    r=b.pow(p);
	    if(r.compareTo(BigDecimal.ONE)==-1){
		System.out.println(r.stripTrailingZeros().toPlainString().substring(1));
	    }
	    else{
		System.out.println(r.stripTrailingZeros().toPlainString());
	    }
	}
    }
}

