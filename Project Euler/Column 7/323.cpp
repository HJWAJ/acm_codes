#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
/**
 * dp[i]��ʾ����iλ��������
 * ��ǰ״̬��һ���µ���ȡ��ʱ������һ������ת������ǰ״̬���ȵ�ǰ���1��״̬��������һֱ����״̬����ˣ�
 * dp[32] = (dp[32] + 1) * (c(32, 32) / 2^32) + (dp[31] + 1) * (c(32, 31) / 2^32) + ... + (dp[1] + 1) * (c(32, 1) / 2^32) + 1 * (c(32, 0) / 2^32)
 * ������
 * dp[1] = (c(1, 1) / 2) * (dp[1] + 1) + (c(1, 0) / 2) * 1
 * �����൱���г����Է����飬�ⷽ�̼��ɡ�
 */
long double dp[33];
long long c[33][33];
void init()
{
    for (int i = 0; i <= 32; i++)
        for (int j = 0; j <= 32; j++)
        {
            if (j == 0) c[i][j] = 1;
            else if (j > i) c[i][j] = 0;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
}
int main()
{
    init();
    dp[0] = 0;
    for (int i = 1; i <= 32; i++)
    {
        dp[i] = 1.0;
        for (int j = 0; j < i; j++) dp[i] += c[i][j] * (dp[j] + 1.0);
        dp[i] /= (1LL << i) - 1.0;
    }
    printf("%.10lf\n", (double)dp[32]);
    return 0;
}
