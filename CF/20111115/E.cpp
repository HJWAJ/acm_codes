#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
const long long mod=1000000007LL;
long long ncr[1001][1001] = { { 0 } }, dpm[1001][1001];

void init(int n, int m)
{
        long long ans = 0;
        for(int i = 1; i <= n; i ++)
        {
                for(int j = 1; j <= i; j ++)
                {
                        if(j == 1)
                                ncr[i][j] = i;
                        else if(i == j)
                                ncr[i][j] = 1;
                        else
                                ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
                        ncr[i][j] %= MOD;
                }
        }
}


int main()
{
        int n, m, k;
        long long ans = 0;
        scanf(" %d %d %d", &n, &m, &k);
        init(1000, 1000);
        if(n - 2 * k < 0 || m - 2 * k < 0)
        {
                printf("0\n");
                return 0;
        }
        /*for(int i = 1; i < 10; i ++)
        {
                for(int j = 1; j < i; j ++)
                        printf("%d %d %d\n", i, j, (int) ncr[i][j]);
        }*/
        ans = ncr[n - 1][2 * k] * ncr[m - 1][2 * k];
        ans %= MOD;
        printf("%lld\n", ans);
        return 0;
}
