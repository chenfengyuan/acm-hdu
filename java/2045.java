import java.util.*;

class Main
{
    static final int N=51;
    static long [][][]c=new long [N][3][3];
    static long []d=new long[N];
    public static void cal_c()
    {
	int f,p,i,j;
	for(f=0;f<3;++f){
	    for(p=0;p<3;++p){
		if(p==f){
		    c[0][f][p]=2;
		} else {
		    c[0][f][p]=1;
		}
	    }
	}
	long s;
	for(i=1;i<N;++i){
	    for(f=0;f<3;++f){
		for(p=0;p<3;++p){
		    s=0;
		    for(j=0;j<3;++j){
			if(j!=p){
			    s+=c[i-1][f][j];
			}
		    }
		    c[i][f][p]=s;
		}
	    }
	}
	d[0]=3;
	for(i=1;i<N;++i){
	    d[i]=0;
	    for(j=0;j<3;++j){
		d[i]+=c[i-1][j][j];
	    }
	}
    }
    public static void main(String []args)
    {
	cal_c();
	Scanner cin = new Scanner(System.in);
	while(cin.hasNextInt()){
	    System.out.println(d[cin.nextInt()-1]);
	}
    }
}

