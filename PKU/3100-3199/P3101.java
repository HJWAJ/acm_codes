import java.util.*;
import java.math.*;
public class Main {
	static BigInteger gcd(BigInteger a,BigInteger b)
	{
		if(b.equals(BigInteger.ZERO))return a;
		return gcd(b,a.mod(b));
	}
	static BigInteger lcm(BigInteger a,BigInteger b)
	{
		return a.divide(gcd(a,b)).multiply(b);
	}
	public static void main(String[] args)
	{
		int n,i,flag;
		BigInteger GCD,LCM,tmp,tmp1,tmp2;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			n=cin.nextInt();
			BigInteger a[]=new BigInteger [n];
			for(i=0;i<n;i++)a[i]=cin.nextBigInteger();
			Arrays.sort(a);
			flag=1;
			for(i=1;i<n;i++)
				if(a[i]!=a[flag-1])
				{
					a[flag]=a[i];
					flag++;
				}
			tmp1=a[flag-1].subtract(a[0]).multiply(BigInteger.valueOf(2));
			tmp2=a[0].multiply(a[flag-1]);
			tmp=gcd(tmp1,tmp2);
			tmp1=tmp1.divide(tmp);
			tmp2=tmp2.divide(tmp);
			GCD=tmp1;
			LCM=tmp2;
			for(i=1;i<flag-1;i++)
			{
				tmp1=a[flag-1].subtract(a[i]).multiply(BigInteger.valueOf(2));
				tmp2=a[i].multiply(a[flag-1]);
				tmp=gcd(tmp1,tmp2);
				tmp1=tmp1.divide(tmp);
				tmp2=tmp2.divide(tmp);
				GCD=gcd(GCD,tmp1);
				LCM=lcm(LCM,tmp2);
			}
			tmp=gcd(GCD,LCM);
			GCD=GCD.divide(tmp);
			LCM=LCM.divide(tmp);
			System.out.println(LCM+" "+GCD);
		}
	}
}
