import java.util.*;
import java.math.*;
public class Main {
	public static void main(String[] args){
		BigDecimal a=BigDecimal.ZERO;
		BigDecimal exp,expten=BigDecimal.valueOf(0.1),tmp,tmp1,tmp2,tmp3;
		int i,j,k,sum=0,cnt;
		String s;
		for(i=1;i<=100;i++){
			if(Math.sqrt(i)==Math.floor(Math.sqrt(i))){
				continue;
			} else {
				exp=BigDecimal.valueOf(1);
				for(j=0;j<10;j++){
					if(j*j<i && (j+1)*(j+1)>i){
						a=BigDecimal.valueOf(j);
					}
				}
				for(j=0;j<100;j++){
					exp=exp.multiply(expten);
					for(k=0;k<10;k++){
						tmp=a.add(BigDecimal.valueOf(k).multiply(exp));
						tmp1=a.add(BigDecimal.valueOf(k+1).multiply(exp));
						tmp2=tmp.multiply(tmp);
						tmp3=tmp1.multiply(tmp1);
						if(tmp2.compareTo(BigDecimal.valueOf(i))==-1 && tmp3.compareTo(BigDecimal.valueOf(i))==1){
							a=tmp;
							break;
						}
					}
				}
				s=a.toString();
				cnt=0;
				for(j=0;;j++){
					if(s.charAt(j)!='.'){
						cnt++;
						sum+=s.charAt(j)-'0';
						if(cnt==100){
							break;
						}
					}
				}
			}
		}
		System.out.println(sum);
	}
}
