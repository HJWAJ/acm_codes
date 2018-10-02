import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args)
	{
		int i;
		BigInteger c=BigInteger.ONE;
		for(i=0;i<20;i++)
		{
			c=c.multiply(BigInteger.valueOf(40-i));
			c=c.divide(BigInteger.valueOf(i+1));
		}
		System.out.println(c);
	}
}
