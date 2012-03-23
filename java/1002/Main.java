import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String[] args)
		{
			Scanner cin= new Scanner(System.in);
			BigInteger a,b;
			int i,n;
			n=cin.nextInt();
			for(i=1;i<=n;++i){
				a=cin.nextBigInteger();
				b=cin.nextBigInteger();
				System.out.println("Case "+i+":");
				System.out.println(a+" + "+b+" = "+a.add(b));
				if(i<n)
					System.out.println("");
			}
		}
}

