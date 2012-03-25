import java.util.*;

class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        int a, b;
	int [][]arr=new int[500][10000];
	int i;
	for(i=0;i<500;++i){
	    Arrays.fill(arr[i],42);
	}
        while(cin.hasNextInt())
        {
            a = cin.nextInt();
            b = cin.nextInt();
            System.out.println(a + b);
        }
    }
}
