import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args)
	{
		BigInteger f1,f2,f3;
		int n=3;
		f1=BigInteger.ONE;
		f2=BigInteger.ONE;
		f3=f1.add(f2);
		while(f3.toString().length()<1000)
		{
			f1=f2;
			f2=f3;
			f3=f1.add(f2);
			n++;
		}
		System.out.println(n);
	}
}
