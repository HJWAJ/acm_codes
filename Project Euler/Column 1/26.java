import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args)
	{
		int i;
		int max=0,len,maxi=0;
		for(i=3;i<1000;i+=2)
			if(i%10==1 || i%10==3 || i%10==7 || i%10==9)
			{
				BigInteger a=BigInteger.valueOf(9);
				while(a.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)==false)
				{
					a=a.multiply(BigInteger.TEN);
					a=a.add(BigInteger.valueOf(9));
				}
				len=a.toString().length();
				if(len>max)
				{
					max=len;
					maxi=i;
				}
			}
		System.out.println(maxi);
	}
}
