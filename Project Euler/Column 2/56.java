import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args){
		int i,j,max=0,sum;
		for(i=1;i<=100;i++)
			for(j=1;j<=100;j++){
				sum=0;
				BigInteger a=BigInteger.valueOf(i).pow(j);
				while(!a.equals(BigInteger.ZERO)){
					sum+=a.mod(BigInteger.TEN).intValue();
					a=a.divide(BigInteger.TEN);
				}
				if(sum>max)max=sum;
			}
		System.out.println(max);
	}
}
