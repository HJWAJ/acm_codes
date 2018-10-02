package test;
import java.util.*;
import java.math.*;
public class test {
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		int n,i;
		BigInteger ans[]=new BigInteger [505];
		ans[0]=BigInteger.ONE;
		ans[1]=BigInteger.valueOf(3);
		for(i=2;i<500;i++)ans[i]=ans[i-1].add(ans[i-2].multiply(BigInteger.valueOf(2)));
		while(cin.hasNextBigInteger())
		{
			n=cin.nextInt();
			if(n==0)System.out.println(1);
			else System.out.println(ans[n-1]);
		}
	}
}
