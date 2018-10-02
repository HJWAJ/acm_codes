import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args){
		/**
		 * 首先可以看到，不考虑最后的+1，则可以：a[0]=0;a[n]=1/(a[n-1]+2);
		 * 然后把+1算进去，则可以a[0]=1;a[n]=1/(a[n-1]+1)+1;也就是a[n]=(a[n-1]+2)/(a[n-1]+1);
		 * 令a[n]=b[n]/c[n];代入a[n-1]化简可得b[n]=b[n-1]+2*c[n-1];c[n]=b[n-1]+c[n-1];
		 * 这样b[0]=c[0]=1是一组满足的初始值，即可直接计算1000项。
		 */
		int i,cnt=0;
		BigInteger a,b,aa,bb;
		a=b=BigInteger.ONE;
		for(i=0;i<1000;i++)
		{
			aa=a.add(b.multiply(BigInteger.valueOf(2)));
			bb=a.add(b);
			if(aa.toString().length()>bb.toString().length())cnt++;
			a=aa;b=bb;
		}
		System.out.println(cnt);
	}
}
