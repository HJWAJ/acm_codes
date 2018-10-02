#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long pri[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
long long multi(long long a, long long b, long long n)
{
	long long tmp = 0;
	b = (b % n + n) % n;
	while(b)
	{
		if(b & 1)
		{
			tmp += a;
			if(tmp >= n)
				tmp -= n;
		}
		a <<= 1;
		if(a >= n)a -= n;
		b >>= 1;
	}
	return tmp;
}
long long multimod(long long a, long long m, long long n)
{
	long long tmp=1;
	a %= n;
	while(m)
	{
		if(m & 1) tmp = multi(tmp, a, n);
		a = multi(a, a, n);
		m >>= 1;
	}
	return tmp;
}
bool miller_rabin(long long n)
{
	if(n < 2)
		return false;
	if(n == 2)
		return true;
	if(!(n & 1))
		return false;
	long long k = 0, i, j, m, a;
	m = n - 1;
	while(!(m & 1)) m >>= 1, k++;
	for(i = 0; i < 10; i++)
	{
		if(pri[i] >= n)
			return true;
		a = multimod(pri[i], m, n);
		if(a == 1) continue;
		for(j = 0; j < k; j++)
		{
			if(a == n - 1)
				break;
			a = multi(a, a, n);
		}
		if(j == k)
			return false;
	}
	return true;
}
const long long pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int main()
{
    long long sum = 0;
    // 8个0
    for (int i = 1; i < 10; i++)
        for (int j = 1; j < 10; j++)
            if (miller_rabin(1000000000LL * i + j))
            {
                sum += 1000000000LL * i + j;
            }
    // 1~9, 9个或8个
    for (int i = 1; i < 10; i++)
    {
        bool flag = false;
        // 9个
        // insert j
        for (int j = 0; j < 10; j++)
        {
            if (i == j) continue;
            // insert at k
            for (int k = 0; k < 10; k++)
            {
                if (j == 0 && k == 9) continue;
                long long tmp = j * pow10[k];
                for (int l = 0; l < 10; l++)
                    if (l != k)
                        tmp += pow10[l] * i;
                if (miller_rabin(tmp))
                {
                    flag = true;
                    sum += tmp;
                }
            }
        }
        if (flag) continue;
        // 8个
        // insert j k at jj kk
        for (int j = 0; j < 10; j++)
        {
            if (j == i) continue;
            for (int k = 0; k < 10; k++)
            {
                if (k == i) continue;
                for (int jj = 0; jj < 10; jj++)
                    for (int kk = jj + 1; kk < 10; kk++)
                    {
                        if (j == 0 && jj == 9) continue;
                        if (k == 0 && kk == 9) continue;
                        long long tmp = j * pow10[jj] + k * pow10[kk];
                        for (int l = 0; l < 10; l++)
                            if (l != jj && l != kk)
                                tmp += i * pow10[l];
                        if (miller_rabin(tmp))
                        {
                            sum += tmp;
                        }
                    }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
