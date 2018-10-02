import java.util.*;
import java.math.*;

public class Main {
	public static BigInteger Abs(BigInteger num) {
		return num.abs();
	}

	public static BigInteger Min(BigInteger num1, BigInteger num2) {
		return num1.min(num2);
	}

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger n, m;
		while (cin.hasNext()) {
			m = cin.nextBigInteger();
			n = cin.nextBigInteger();
			if (m.compareTo(n) > 0) {
				System.out.println(m.subtract(n));
			} else {
				BigInteger x1, x2, y1, y2, x;
				x = n;
				x1 = BigInteger.ZERO;
				x2 = BigInteger.ONE;
				BigInteger ans = n.subtract(m);
				while (x.multiply(BigInteger.valueOf(2)).compareTo(m) > 0) {
					if (x.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO) == 0) {
						y1 = Min(x1.add(BigInteger.valueOf(1)), x2
								.add(BigInteger.valueOf(2)));
						y2 = Min(x1.add(BigInteger.valueOf(2)), x2
								.add(BigInteger.valueOf(2)));
					} else {
						y1 = Min(x1.add(BigInteger.valueOf(2)), x2
								.add(BigInteger.valueOf(2)));
						y2 = Min(x1.add(BigInteger.valueOf(2)), x2
								.add(BigInteger.valueOf(1)));
					}

					x = x.divide(BigInteger.valueOf(2));
					x1 = y1;
					x2 = y2;
					ans = Min(ans, Abs(x.subtract(m)).add(y1));
					ans = Min(ans, Abs(x.subtract(m).add(BigInteger.ONE)).add(
							y2));
				}

				System.out.println(ans);
			}
		}
	}
}
