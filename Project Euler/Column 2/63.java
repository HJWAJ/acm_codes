import java.util.*;
import java.math.*;
/**
 *
 * a^n��nλ������Ȼa<10����9^21=9E20������ö��a=1~9��n=1~20������0^1��1λ��������cnt+1
 *
 */
public class Main {
	static int test(BigInteger a)
	{
		int cnt=0;
		while(!a.equals(BigInteger.ZERO))
		{
			cnt++;
			a=a.divide(BigInteger.TEN);
		}
		return cnt;
	}
	public static void main(String args[])
	{
		int n,a,i,cnt=0;
		for(n=1;n<21;n++)
			for(a=1;a<10;a++)
			{
				BigInteger num=BigInteger.ONE;
				for(i=0;i<n;i++)num=num.multiply(BigInteger.valueOf(a));
				if(test(num)==n)cnt++;
			}
		System.out.println(cnt+1);
	}
}
