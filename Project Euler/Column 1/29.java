//暴力，有点小内疚的感觉

import java.util.*;
import java.math.*;
public class Main {
	static BigInteger multimod(BigInteger a,int n)
	{
		BigInteger res=BigInteger.ONE;
		for(int i=0;i<n;i++)res=res.multiply(a);
		return res;
	}
	public static void main(String[] args)
	{
		int i,j;
		int cnt=0;
		BigInteger[] a=new BigInteger [10000];
		for(i=0;i<10000;i++)a[i]=BigInteger.ZERO;
		for(i=2;i<=100;i++)
			for(j=2;j<=100;j++)
				a[(i-1)*100+j-1]=multimod(BigInteger.valueOf(i),j);
		Arrays.sort(a,0,10000);
		for(i=0;i<10000;i++)
		{
			if(a[i].equals(BigInteger.ZERO))cnt++;
			else break;
		}
		for(;i<10000-1;i++)
			if(a[i].equals(a[i+1]))cnt++;
		System.out.print(10000-cnt);
	}
}
