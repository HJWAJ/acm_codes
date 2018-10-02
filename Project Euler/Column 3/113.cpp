#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100;
long long dp[MAX][10];
int main()
{
    int i, j, k;
    long long sum = 0;
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < MAX; i++)
        for (j = 0; j < 10; j++)
        {
            if (i == 0) dp[i][j] = 1;
            else
            {
                for (k = 0; k <= j; k++)
                    dp[i][j] += dp[i - 1][k];
            }
        }
    for (i = 0; i < 10; i++)
        sum += dp[MAX - 1][i];
    // �������

    memset(dp, 0, sizeof(dp));
    for (i = 0; i < MAX; i++)
        for (j = 0; j < 10; j++)
        {
            if (i == 0) dp[i][j] = 1;
            else
            {
                for (k = 9; k >= j; k--)
                    dp[i][j] += dp[i - 1][k];
            }
        }
    for (i = 0; i < MAX; i++)
        for (j = 0; j < 10; j++)
            sum += dp[i][j];
    sum -= (MAX - 1);
    // �ݼ���ɣ���ȥMAX - 1����Ϊ0,00,000,...�����ظ�����

    sum -= 10 * MAX - (MAX - 1) + 1;
    // �ȵ����ֵݼ��ģ���0~9, 00~99, ..., ���ظ���0��Ҫ��ȥ��Ȼ��0���㣬����Ҫ+1
    cout << sum << endl;
    return 0;
}
