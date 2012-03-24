import java.util.*;

class block
{
    public int x,y,z;
    public block(int x,int y,int z)
    {
	this.x=x;
	this.y=y;
	this.z=z;
    }
        
    @Override
    public String toString() {
	return x+"\t"+y+"\t"+z;
    }
}
class cmp_area implements Comparator<block>
{
    public int compare(block a,block b)
    {
	if (a.x*a.y>b.x*b.y)
	    return 1;
	else
	    return 0;
    }
}

class cmp_edge implements Comparator<block>
{
    public int compare(block a,block b)
    {
	if(a.x>b.x&&a.y>b.y||a.x>b.y&&a.y>b.x)
	    return 1;
	else if(a.x<b.x&&a.y<b.y||a.x<b.y&&a.y<b.x)
	    return -1;
	else
	    return 0;
    }
}
    
class Main
{
    public static final int N=30*3;
    public static void main(String []args)
    {
	block[]arr=new block[N];
	block temp;
	int []q=new int[N];
	int n,i,j,max;
	int x,y,z;
	cmp_edge cmp=new cmp_edge();
	int Case=0;
	Scanner sc=new Scanner(System.in);
	while((n=sc.nextInt())!=0){
	    ++Case;
	    Arrays.fill(q,0);
	    j=0;
	    for(i=0;i<n;++i){
		x=sc.nextInt();
		y=sc.nextInt();
		z=sc.nextInt();
		arr[j++]=new block(x,y,z);
		if(z!=y){
		    arr[j++]=new block(z,x,y);
		}
		if(z!=x && x!=y){
		    arr[j++]=new block(y,z,x);
		}
	    }
	    n=j;
	    Arrays.sort(arr,0,n,new cmp_area());
	    for(i=0;i<n;++i){
		max=0;
		for(j=0;j<i;++j){
		    if(cmp.compare(arr[i],arr[j])>0){
			max=Math.max(max,q[j]);
		    }
		}
		q[i]=max+arr[i].z;
	    }
	    for(max=0,i=0;i<n;++i){
		max=Math.max(max,q[i]);
	    }
	    System.out.println("Case "+Case+": maximum height = "+max);
	    // for(i=0;i<n;++i){
	    // 	System.out.println(arr[i].toString());
	    // }
	    // System.out.println("");
	    // System.out.println(Arrays.toString(q));
	}
    }
}
