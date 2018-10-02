package test;
import java.util.*;
import java.math.*;
public class test {
	public static void main(String[] args)
	{
		int i,cnt;
		BigInteger MAX=BigInteger.TEN;
		BigInteger aa,bb;
		for(i=1;i<100;i++)MAX=MAX.multiply(BigInteger.TEN);
		BigInteger f[]=new BigInteger[100005];
		f[1]=BigInteger.valueOf(1);
		f[2]=BigInteger.valueOf(2);
		i=2;
		while(f[i].compareTo(MAX)==-1)
		{
			i++;
			f[i]=f[i-2].add(f[i-1]);
		}
		Scanner cin=new Scanner(System.in);
		while(true)
		{
			aa=cin.nextBigInteger();
			bb=cin.nextBigInteger();
			if(aa.equals(BigInteger.ZERO) && bb.equals(BigInteger.ZERO))break;
			cnt=0;
			i=1;
			while(f[i].compareTo(aa)==-1)i++;
			while(f[i].compareTo(bb)<1)
			{
				i++;
				cnt++;
			}
			System.out.println(cnt);
		}
	}
}
