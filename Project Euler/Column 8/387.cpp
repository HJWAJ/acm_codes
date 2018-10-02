#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
long long sum = 0;
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
void dfs(long long n, int digit_num, int digit_sum)
{
    if (digit_num == 14) return;
    for (int i = 0; i < 10; i++)
    {
        if (digit_sum + i != 0 && (n * 10 + i) % (digit_sum + i) == 0)
        {
            if (miller_rabin((n * 10 + i) / (digit_sum + i)))
            {
                for (int j = 0; j < 10; j++)
                {
                    if (miller_rabin((n * 10 + i) * 10 + j))
                    {
                        sum += (n * 10 + i) * 10 + j;
                    }
                }
            }
            dfs(n * 10 + i, digit_num + 1, digit_sum + i);
        }
    }
}
int main()
{
    dfs(0, 1, 0);
    cout << sum << endl;
    return 0;
}
