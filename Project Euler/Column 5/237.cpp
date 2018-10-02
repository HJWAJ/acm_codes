#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
/**
 * 插头dp
 * 竖过来看，枚举下插头的情况，可能性有7种如下：
 * 0代表无下插头，1、2代表有下插头，1和1连通，2和2连通
 * 0：0 0 0 0（只有最后一行出现）
 * 1：0 0 1 1
 * 2：1 1 0 0
 * 3：1 0 0 1
 * 4：0 1 1 0
 * 5：1 1 2 2
 * 6：1 2 2 1
 * 7：0 1 0 1
 * 8：1 0 1 0
 * 第一行看做是最左一格和最右一格分别向第0行连通，然后第0行横着形成连通
 * 构造状态转移矩阵g[MAT_SIZE][MAT_SIZE]，g[i][j]表示状态i到状态j有g[i][j]种方法可达
 * 然后计算g^(n-1)，得到的矩阵中，g'[i][j]表示从i到j走n-1步有多少种方法可达
 * 然后枚举起点的情况，将所有的g'[start][end]相加即为结果
 */
const long long N = 1000000000000LL;
const int MAT_SIZE = 9;
const long long MOD = 100000000;
long long g[MAT_SIZE][MAT_SIZE] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 1, 0, 0, 0,
    0, 0, 0, 1, 0, 1, 0, 0, 0,
    1, 1, 1, 0, 1, 0, 1, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 1, 0, 0, 0,
    1, 1, 1, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 1, 0
};
long long ans[MAT_SIZE][MAT_SIZE];
void make_ans_unit_mat()
{
    for (int i = 0; i < MAT_SIZE; i++)
        ans[i][i] = 1;
}
void mat_multi(long long a[MAT_SIZE][MAT_SIZE], long long b[MAT_SIZE][MAT_SIZE])
{
    int c[MAT_SIZE][MAT_SIZE];
    memset(c, 0, sizeof(c));
    for(int i = 0; i < MAT_SIZE; i++)
        for(int j = 0; j < MAT_SIZE; j++)
            if(a[i][j])
                for(int k = 0; k < MAT_SIZE; k++)
                {
                    c[i][k] += a[i][j] * b[j][k] % MOD;
                    c[i][k] %= MOD;
                }
    for(int i = 0; i < MAT_SIZE; i++)
        for(int j = 0; j < MAT_SIZE; j++)
            a[i][j] = c[i][j];
}
int main()
{
    long long n = N;
    make_ans_unit_mat();
    while (n)
    {
        if (n & 1LL) mat_multi(ans, g);
        mat_multi(g, g);
        n >>= 1;
    }
    cout << ans[3][0] % MOD << endl;
    return 0;
}
