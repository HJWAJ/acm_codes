#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;
/**
 * ��gcd(a,b,c) = 1, a,b,c <=N �Ķ�����
 * ��Ī����˹����,��g(n)Ϊgcd(x,y,z)=n�ĸ�����f(n)Ϊn | g(i*n)�ĸ���
 * ��ô��f(n)=sigma(n|d,g(d))��g(n)=sigma(n|d, mu(d/n)*f(d))
 * ����Ҫ�����g(1)����g(1)=sigma(n|d, mu(d)*f(d))
 * f(d)=(n/d)*(n/d)*(n/d)������g(1)=sigma( mu(d)*(n/d)*(n/d)*(n/d) )
 * ע�������Ǵ�1��ʼ��ģ�����Ҫ����ƽ�����������������ᡣ
 * muֱ����̫��������ڴ治������Ҫ�����ļ�������
 *
 * update:
 * �ļ���������IOƿ�������ô�С�������С����㡣
 * ��������i��n/i�ܶ���һ����ֵ�����Ծͱ�������sigma(mu(i))*(n/i)*(n/i)*(n/i+3)
 * ����������������Ż���
 */

//const long long N = 1000000;
const long long N = 10000000000LL;
const int SMALL_N = (int)pow((double)N, 2.0 / 3);
long long mu[10000000], prime[1000000], prime_num = 0;
long long ans[105], tmp[105], ans_len = 0, tmp_len = 0;
map<long long, long long> mymap;
void mobius_sum_table()
{
    fill(mu, mu + SMALL_N, -2);
    mu[1] = 1;
    for (long long i = 2; i < SMALL_N; i++)
    {
        if (mu[i] == -2)
        {
            mu[i] = -1;
            prime[prime_num++] = i;
        }
        for (int j = 0; j < prime_num; j++)
        {
            if (i * prime[j] > SMALL_N) break;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    for (long long i = 2; i < SMALL_N; i++)
        mu[i] += mu[i - 1];
}
long long get_mu_sum(long long n)
{
    if (n < SMALL_N) return mu[n];
    if (mymap.count(n) == 1) return mymap[n];
    long long result = 1, i = 2, j;
    while (i <= n)
    {
        j = n / (n / i);
        result -= get_mu_sum(n / i) * (j - i + 1);
        i = j + 1;
    }
    mymap[n] = result;
    return result;
}
void add(long long i, long long current, long long last)
{
    long long n = N / i + 1;
    long long nn = n;
    // tmp = n;
    tmp_len = 0;
    memset(tmp, 0, sizeof(tmp));
    while (n)
    {
        tmp[tmp_len++] = n % 10;
        n /= 10;
    }
    // tmp *= n;
    n = nn;
    for (int i = 0; i < tmp_len; i++)
        tmp[i] *= n;
    for (int i = 0; i < tmp_len; i++)
    {
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
    while (tmp[tmp_len])
    {
        tmp[tmp_len + 1] += tmp[tmp_len] / 10;
        tmp[tmp_len] %= 10;
        tmp_len++;
    }
    // tmp *= n;
    n = nn;
    for (int i = 0; i < tmp_len; i++)
        tmp[i] *= n;
    for (int i = 0; i < tmp_len; i++)
    {
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
    while (tmp[tmp_len])
    {
        tmp[tmp_len + 1] += tmp[tmp_len] / 10;
        tmp[tmp_len] %= 10;
        tmp_len++;
    }
    // tmp--;
    tmp[0]--;
    int pos = 0;
    while (tmp[pos] < 0 && pos < tmp_len - 1)
    {
        tmp[pos] += 10;
        tmp[pos + 1]--;
        pos++;
    }
    if (pos == tmp_len - 1 && tmp[pos] == 0) tmp_len--;
    // tmp *= current - last;
    n = current - last;
    for (int i = 0; i < tmp_len; i++)
        tmp[i] *= n;
    for (int i = 0; i < tmp_len; i++)
    {
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
    while (tmp[tmp_len])
    {
        tmp[tmp_len + 1] += tmp[tmp_len] / 10;
        tmp[tmp_len] %= 10;
        tmp_len++;
    }
    // ans += tmp;
    for (int i = 0; i < tmp_len; i++)
        ans[i] += tmp[i];
}
void print()
{
    // format
    int i;
    for (i = 100; i >= 0; i--)
        if (ans[i] != 0)
        {
            ans_len = i;
            break;
        }
    while (ans[ans_len])
    {
        ans[ans_len + 1] += ans[ans_len] / 10;
        ans[ans_len++] %= 10;
    }
    for (i = 0; i < ans_len; i++)
    {
        if (ans[i] < 0)
        {
            ans[i + 1] += ans[i] / 10 - 1;
            ans[i] %= 10;
            ans[i] += 10;
        }
        if (ans[i] > 0)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    while(ans[ans_len - 1] == 0) ans_len--;
    // print
    for (i = ans_len - 1; i >= ans_len - 9; i--)
        printf("%lld", ans[i]);
    for (i = 8; i >= 0; i--)
        printf("%lld", ans[i]);
    puts("");
}
void solve()
{
    long long i = 1, j, last = 0, current = 0;
    //long long ans = 0;
    while (i <= N)
    {
        j = N / (N / i);
        current = get_mu_sum(j);
        //ans += ((N / i + 1) * (N / i + 1) * (N / i + 1) - 1) * (current - last);
        add(i, current, last);
        i = j + 1;
        last = current;
    }
    //cout << ans << endl;
    print();
}
int main()
{
    mobius_sum_table();
    solve();
    return 0;
}
