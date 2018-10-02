import java.util.*;
import java.math.*;
class PellAns
{
	private BigInteger p,q;
	PellAns(BigInteger pp,BigInteger qq)
	{
		this.p=pp;
		this.q=qq;
	}
	PellAns(){}
	void set(PellAns P)
	{
		this.p=P.p;
		this.q=P.q;
	}
	void set(BigInteger pp,BigInteger qq)
	{
		this.p=pp;
		this.q=qq;
	}
	BigInteger get()
	{
		return this.p;
	}
	public PellAns solve(int n)
	{
		PellAns s[]=new PellAns[4],w[]=new PellAns[4];
		BigInteger a[]=new BigInteger[4];
		s[0]=new PellAns(BigInteger.ZERO,BigInteger.ONE);
		s[1]=new PellAns(BigInteger.ONE,BigInteger.ZERO);
		w[1]=new PellAns(BigInteger.ZERO,BigInteger.ONE);
		s[2]=new PellAns();
		s[3]=new PellAns();
		w[0]=new PellAns();
		w[2]=new PellAns();
		w[3]=new PellAns();
		a[2]=BigInteger.valueOf((int)Math.sqrt((double)(n)));
		a[0]=BigInteger.valueOf((int)Math.sqrt((double)(n)));
		while(true)
		{
			w[2].p=BigInteger.ZERO.subtract(w[1].p).add(a[2].multiply(w[1].q));
			w[2].q=BigInteger.valueOf(n).subtract(w[2].p.multiply(w[2].p)).divide(w[1].q);
			a[3]=w[2].p.add(a[0]).divide(w[2].q);
			s[2].p=a[2].multiply(s[1].p).add(s[0].p);
			s[2].q=a[2].multiply(s[1].q).add(s[0].q);
			if(s[2].p.multiply(s[2].p).subtract(BigInteger.valueOf(n).multiply(s[2].q).multiply(s[2].q)).equals(BigInteger.ONE) && s[2].p.compareTo(BigInteger.ZERO)==1 && s[2].q.compareTo(BigInteger.ZERO)==1)return s[2];
			w[0].set(w[1]);w[1].set(w[2]);a[2]=a[3];s[0].set(s[1]);s[1].set(s[2]);
		}
	}
}
public class Main {
	public static void main(String[] args)
	{
		int n=1,cnt=0;
		BigInteger m=BigInteger.ZERO,tmp;
		while(n<1001)
		{
			if(n==((int)(Math.sqrt((double)n)))*((int)(Math.sqrt((double)n))))
			{
				n++;
				continue;
			}
			else
			{
				PellAns ans = new PellAns();
				ans=ans.solve(n);
				tmp=ans.get();
				if(tmp.compareTo(m)>0)
				{
					m=tmp;
					cnt=n;
				}
			}
			n++;
		}
		System.out.println(cnt);
	}
}
