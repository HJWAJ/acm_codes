#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
bool bo[25000001];
int prime_table_ext()
{
    int i, j, flag = 0;
    memset(bo, 0, sizeof(bo));
    bo[0] = bo[1] = 1;
    for (i = 2; i <= 5000; i++)
        if(!bo[i])
        {
            j = i * i;
            for (; j <= 25000000; j += i) bo[j] = 1;
        }
    for (i = 0; i <= 25000000; i++)
        if (!bo[i] && (long long)i * i <= 25000000)
            bo[i * i] = 0;
}
const long long MOD = 500500507LL;
int main()
{
    prime_table_ext();
    long long ans = 1;
    int cnt = 0;
    for (int i = 0; i <= 25000000; i++)
    {
        if (cnt == 500500) break;
        if (!bo[i])
        {
            ans *= i;
            ans %= MOD;
            cnt++;
        }
    }
    cout << ans << endl;
    return 0;
}
