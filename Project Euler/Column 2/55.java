import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args){
		int cnt=0,num;
		for(int i=1;i<10001;i++){
			num=0;
			BigInteger a=BigInteger.valueOf(i);
			BigInteger b=BigInteger.ZERO;
			BigInteger aa=a;
			while(num<50){
				while(!aa.equals(BigInteger.ZERO)){
					b=b.multiply(BigInteger.TEN);
					b=b.add(aa.mod(BigInteger.TEN));
					aa=aa.divide(BigInteger.TEN);
				}
				a=a.add(b);
				String stra,strb="";
				stra=a.toString();
				int len=stra.length();
				for(int j=0;j<len;j++){
					strb+=stra.substring(len-1-j,len-j);
				}
				if(strb.equals(stra))break;
				aa=a;
				b=BigInteger.ZERO;
				num++;
			}
			if(num==50)cnt++;
		}
		System.out.println(cnt);
	}
}
