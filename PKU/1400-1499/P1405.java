package test;
import java.util.*;
import java.math.*;
public class test {
	public static void main(String[] args)
	{
		Scanner cin=new Scanner(System.in);
		BigInteger a[]=new BigInteger [20];
		a[0]=BigInteger.valueOf(2);
		a[1]=BigInteger.valueOf(3);
		int i;
		for(i=2;i<20;i++)a[i]=a[i-1].subtract(BigInteger.ONE).multiply(a[i-1]).add(BigInteger.ONE);
		int n=cin.nextInt();
		for(i=0;i<n;i++)System.out.println(a[i]);
	}
}
