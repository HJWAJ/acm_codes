import java.util.*;
import java.math.*;
/**
 *
 * 高精度模拟
 *
 */
public class Main {
	public static void main(String[] args){
		int i,ans=0,len;
		BigInteger p,q,tmp,t;
		p=BigInteger.ONE;
		q=BigInteger.valueOf(1);
		for(i=98;i>0;i--)
		{
			if(i%3==0 || i%3==1)tmp=BigInteger.ONE;
			else tmp=BigInteger.valueOf((i/3+1)*2);
			p=p.add(q.multiply(tmp));
			//System.out.println(p+" "+q);
			t=p;
			p=q;
			q=t;
		}
		p=p.add(q.multiply(BigInteger.valueOf(2)));
		//System.out.println(p+" "+q);
		len=p.toString().length();
		for(i=0;i<len;i++)
			ans+=p.toString().charAt(i)-'0';
		System.out.println(ans);
	}
}
