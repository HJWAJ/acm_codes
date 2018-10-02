#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const long long MOD = 1000000007;
int g[8][128][128];
int get_state(bool bo[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res *= 2;
        if (bo[i]) res++;
    }
    return res;
}
void dfs(int i, int n, bool bo[2][8], int state)
{
    if (i == n)
    {
        g[n][state][get_state(bo[1], n)]++;
        return;
    }
    if (bo[0][i]) dfs(i + 1, n, bo, state);
    else
    {
        // 0
        if (i > 0 && !bo[1][i - 1] && !bo[1][i])
        {
            bo[0][i] = bo[1][i - 1] = bo[1][i] = 1;
            dfs(i + 1, n, bo, state);
            bo[0][i] = bo[1][i - 1] = bo[1][i] = 0;
        }
        // 1
        if (i < n - 1 && !bo[1][i] && !bo[1][i + 1])
        {
            bo[0][i] = bo[1][i + 1] = bo[1][i] = 1;
            dfs(i + 1, n, bo, state);
            bo[0][i] = bo[1][i + 1] = bo[1][i] = 0;
        }
        // 2
        if (i < n - 1 && !bo[0][i + 1] && !bo[1][i + 1])
        {
            bo[0][i] = bo[0][i + 1] = bo[1][i + 1] = 1;
            dfs(i + 1, n, bo, state);
            bo[0][i] = bo[0][i + 1] = bo[1][i + 1] = 0;
        }
        // 3
        if (i < n - 1 && !bo[0][i + 1] && !bo[1][i])
        {
            bo[0][i] = bo[0][i + 1] = bo[1][i] = 1;
            dfs(i + 1, n, bo, state);
            bo[0][i] = bo[0][i + 1] = bo[1][i] = 0;
        }
    }
}
void fill_puzzle(int state, int n)
{
    // 0 1
    // 2 3
    bool bo[2][8];
    memset(bo, 0, sizeof(bo));
    for (int i = 0; i < n; i++)
        if (state & (1 << i))
            bo[0][i] = 1;
    dfs(0, n, bo, state);
}
void print(int n)
{
    //if (n != 2) return;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < (1 << n); j++)
            printf("%d ", g[n][i][j]);
        puts("");
    }
}
void init_g(int n)
{
    for (int i = 0; i < (1 << n); i++)
        fill_puzzle(i, n);
}
void init_mask()
{
    memset(g, 0, sizeof(g));
    for (int i = 2; i <= 7; i++)
    {
        init_g(i);
        //print(i);
    }
}
struct mat
{
    long long val[128][128];
    int size;
    void init(int n)
    {
        size = n;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                val[i][j] = 0;
    }
};
mat E(int n)
{
    mat a;
    a.init(n);
    for (int i = 0; i < n; i++)
        a.val[i][i] = 1;
    return a;
}
mat multiply(mat a, mat b)
{
    mat c;
    int n = a.size;
    c.init(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a.val[i][j])
                for (int k = 0; k < n; k++)
                {
                    c.val[i][k] += a.val[i][j] * b.val[j][k];
                    if (c.val[i][k] > MOD) c.val[i][k] %= MOD;
                }
    return c;
}
mat pow(mat a, long long n)
{
    int size = a.size;
    mat b = E(size);
    while (n)
    {
        if (n & 1) b = multiply(a, b);
        a = multiply(a, a);
        n >>= 1;
    }
    return b;
}
mat get_mat(int m)
{
    mat a;
    int n = (1 << m);
    a.size = n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a.val[i][j] = g[m][i][j];
    return a;
}
int main()
{
    init_mask();
    long long n, m;
    while (scanf("%lld%lld", &n, &m) != EOF)
    {
        if (m == 1) puts("0");
        else
        {
            mat dp = get_mat(m);
            dp = pow(dp, n);
            printf("%lld\n", dp.val[0][0]);
        }
    }
    return 0;
}