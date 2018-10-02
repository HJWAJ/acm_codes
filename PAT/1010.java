package acm;

import java.math.BigInteger;
import java.util.Scanner;

class Solve {
	void solve() {
		Scanner cin = new Scanner(System.in);
		String a = cin.next();
		String b = cin.next();
		int tag = cin.nextInt();
		int radix = cin.nextInt();
		if(tag == 2) {
			String tmp = a;
			a = b;
			b = tmp;
		}
		BigInteger aa = BigInteger.ZERO;
		for(int i=0;i<a.length();i++) {
			if(a.charAt(i) <= '9') {
				aa = aa.multiply(BigInteger.valueOf(radix));
				aa = aa.add(BigInteger.valueOf(a.charAt(i) - '0'));
			} else {
				aa = aa.multiply(BigInteger.valueOf(radix));
				aa = aa.add(BigInteger.valueOf(a.charAt(i) - 'a' + 10));
			}
		}
		if(b.length() == 1) {
			int val = 0;
			if(b.charAt(0) <= '9') val = b.charAt(0) - '0';
			else val = b.charAt(0) - 'a' + 10;
			if(aa.intValue() == val) {
				System.out.println(val + 1);
			} else {
				System.out.println("Impossible");
			}
			return;
		}
		int miniRadix = 0;
		for(int i=0;i<b.length();i++) {
			if(b.charAt(i) <= '9') {
				if(miniRadix < b.charAt(i) - '0') {
					miniRadix = b.charAt(i) - '0';
				}
			} else {
				if(miniRadix < b.charAt(i) - 'a' + 10) {
					miniRadix = b.charAt(i) - 'a' + 10;
				}
			}
		}
		BigInteger l = BigInteger.valueOf(miniRadix);
		BigInteger r = aa.add(BigInteger.ONE);
		//System.out.println(l + " " + r);
		BigInteger mid;
		while(l.compareTo(r) <= 0) {
			mid = l.add(r).divide(BigInteger.valueOf(2));
			BigInteger bb = calc(b, mid);
			if(aa.equals(bb)) {
				System.out.println(mid);
				return;
			} else if(aa.compareTo(bb) < 0) {
				r = mid.subtract(BigInteger.ONE);
			} else {
				l = mid.add(BigInteger.ONE);
			}
		}
		System.out.println("Impossible");
	}

	private BigInteger calc(String b, BigInteger mid) {
		BigInteger res = BigInteger.ZERO;
		for(int i=0;i<b.length();i++) {
			res = res.multiply(mid);
			if(b.charAt(i) <= '9') {
				res = res.add(BigInteger.valueOf(b.charAt(i) - '0'));
			} else {
				res = res.add(BigInteger.valueOf(b.charAt(i) - 'a' + 10));
			}
		}
		return res;
	}
}

public class Main {
	public static void main(String[] args) {
		new Solve().solve();
	}
}
