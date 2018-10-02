package test;
import java.util.*;
import java.math.*;
public class test {
	public static int prime_table(int prime[],boolean bo[])
	{
		int i,j,flag=0;
		for(i=0;i<=50000;i++)bo[i]=false;
		bo[0]=true;
		bo[1]=true;
		for(i=2;i<=50000;i++)
		if(!bo[i])
		{
			prime[flag++]=i;
			for(j=2;j<=50000/i;j++)bo[j*i]=true;
		}
		return flag;
	}
	public static int divide(int n,int p[],int a[],int prime[])
	{
	    int sq=(int)(Math.sqrt((double)(n)));
	    int flag=0,num=0;
	    while(true)
	    {
	        if(n==1)break;
	        if(prime[flag]>sq)
	        {
	            p[num]=n;
	            a[num++]=1;
	            break;
	        }
	        if(n%prime[flag]!=0)
	        {
	            flag++;
	            continue;
	        }
	        p[num]=prime[flag];
	        a[num++]=1;
	        n/=prime[flag];
	        while(n%prime[flag]==0)
	        {
	            n/=prime[flag];
	            a[num-1]++;
	        }
	        flag++;
	    }
	    return num;
	}
	public static BigInteger multimod(BigInteger x,BigInteger n)
	{
	    BigInteger tmp=x,res=BigInteger.ONE;
	    while(!n.equals(BigInteger.ZERO))
	    {
	        if(!n.and(BigInteger.ONE).equals(BigInteger.ZERO))
	        {
	            res=res.multiply(tmp);
	        }
	        tmp=tmp.multiply(tmp);
	        n=n.shiftRight(1);
	    }
	    return res;
	}
	public static void main(String[] args)
	{
		BigInteger tmp;
		int prime[]=new int [50005];
		int p[]=new int [50005];
		int a[]=new int [50005];
		boolean bo[]=new boolean [50005];
		prime_table(prime,bo);
		Scanner cin=new Scanner(System.in);
		int n,m,i,num;
		while(cin.hasNextInt())
		{n=cin.nextInt();
		m=cin.nextInt();
		BigInteger ans=multimod(BigInteger.valueOf(m),BigInteger.valueOf(n));
		//if(BigInteger.valueOf(m).isProbablePrime(100))ans=ans.subtract(BigInteger.ONE);
		//else
		{

			num=divide(m,p,a,prime);
			for(i=0;i<num;i++)
			{
				tmp=multimod(BigInteger.valueOf(p[i]),BigInteger.valueOf(n));
				ans=ans.divide(tmp);
				ans=ans.multiply(tmp.subtract(BigInteger.ONE));
			}
		}
		System.out.println(ans);
	}}
}
