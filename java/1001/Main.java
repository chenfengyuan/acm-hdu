import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	public static void main(String args[])
		{
			Scanner cin = new Scanner(System.in);
			BigInteger s=BigInteger.valueOf(0);

			while(cin.hasNextBigInteger()){
				s=cin.nextBigInteger();
				System.out.println(s.add(BigInteger.ONE).multiply(s).divide(BigInteger.valueOf(2)) +"\r\n");
			}
		}
}



