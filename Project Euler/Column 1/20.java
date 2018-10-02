import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args)
	{
		BigInteger ans=BigInteger.ONE;
		int i;
		for(i=1;i<=100;i++)ans=ans.multiply(BigInteger.valueOf(i));
		String s=ans.toString();
		int len=s.length();
		int cnt=0;
		for(i=0;i<len;i++)cnt+=(s.charAt(i)-'0');
		System.out.println(cnt);
	}
}
