import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args){
		/**
		 * ���ȿ��Կ���������������+1������ԣ�a[0]=0;a[n]=1/(a[n-1]+2);
		 * Ȼ���+1���ȥ�������a[0]=1;a[n]=1/(a[n-1]+1)+1;Ҳ����a[n]=(a[n-1]+2)/(a[n-1]+1);
		 * ��a[n]=b[n]/c[n];����a[n-1]����ɵ�b[n]=b[n-1]+2*c[n-1];c[n]=b[n-1]+c[n-1];
		 * ����b[0]=c[0]=1��һ������ĳ�ʼֵ������ֱ�Ӽ���1000�
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
