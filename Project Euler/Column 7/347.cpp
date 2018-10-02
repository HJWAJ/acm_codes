#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long prime[2000000];
bool bo[16000001];
int prime_table()
{
    int i, j, flag=0;
    bo[0] = bo[1] = 1;
    for (i = 2; i <= 4000; i++)
        if(!bo[i])
        {
            j = i * i;
            for (; j <= 16000000; j += i) bo[j] = 1;
        }
    for (i = 0; i <= 16000000; i++)
        if(!bo[i]) prime[flag++] = i;
    return flag;
}
const int N = 10000000;
long long calc(int i, int j, int k, int l)
{
    long long res = 1;
    for (int n = 0; n < j; n++) res *= prime[i];
    for (int n = 0; n < l; n++) res *= prime[k];
    return res;
}
int main()
{
    prime_table();
    long long sum = 0;
    for (int i = 0; prime[i] < N; i++)
    {
        if (prime[i] * prime[i + 1] > N) break;
        for (int j = i + 1; prime[i] * prime[j] <= N; j++)
        {
            long long tmpi = prime[i];
            long long m = 0;
            for (int k = 1; tmpi * prime[j] <= N; k++)
            {
                long long tmpj = prime[j];
                for (int l = 1; tmpi * tmpj <= N; l++)
                {
                    if (tmpi * tmpj > m) m = tmpi * tmpj;
                    tmpj *= prime[j];
                }
                tmpi *= prime[i];
            }
            sum += m;
        }
    }
    cout << sum << endl;
    return 0;
}
