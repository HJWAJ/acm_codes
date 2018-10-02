import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args)
	{
		int n=1000,res=0,len,i;
		BigInteger ans=BigInteger.ONE,a=BigInteger.valueOf(2);
		while(n!=0)
		{
			if((n&1)!=0)ans=ans.multiply(a);
			a=a.multiply(a);
			n>>=1;
		}
		String s=ans.toString();
		len=s.length();
		for(i=0;i<len;i++)res+=(int)(s.charAt(i)-'0');
		System.out.println(res);
	}
}
