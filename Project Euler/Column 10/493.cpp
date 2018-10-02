#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
long long comb[71][21];
long long denominator, numerator;
void init()
{
    for (int i = 1; i <= 20; i++) comb[0][i] = 0;
    for (int i = 0; i <= 70; i++) comb[i][0] = 1;
    for (int i = 1; i <= 70; i++)
        for (int j = 1; j <= 20; j++)
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
}
long long c(int n, int r)
{
    if (r < 0 || r > n) return 0;
    return comb[n][r];
}
void dfs(int divide[], int sum, int num)
{
    long long tmp;
    if (num == 8) return;
    if (sum == 0)
    {
        tmp = num * c(7, num);
        for (int i = 0; i < num; i++)
            tmp *= c(10, divide[i]);
        numerator += tmp;
        return;
    }
    for (int i = 1; i <= sum; i++)
    {
        divide[num] = i;
        dfs(divide, sum - i, num + 1);
    }
}
int main()
{
    init();
    denominator = c(70, 20);
    int divide[7];
    dfs(divide, 20, 0);
    printf("%.9lf\n", numerator * 1.0 / denominator);
    return 0;
}
