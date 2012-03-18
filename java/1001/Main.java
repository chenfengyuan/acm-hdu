import java.io.*;
import java.util.*;

public class Main
{
	public static void main(String args[]) throws IOException
		{
			// Scanner cin=new Scanner(System.in);
			// int a,b;

			// while(cin.hasNextInt()){
			// 	a=cin.nextInt();
			// 	b=cin.nextInt();
			// 	System.out.println(a+b);
			// }
			StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
			PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
			int a,b;
			while(in.nextToken()!=StreamTokenizer.TT_EOF){
				a=(int)in.nval;
				in.nextToken();
				b=(int)in.nval;
				out.println(a+b);
			}
			out.flush();
		}
}








