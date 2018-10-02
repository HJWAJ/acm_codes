#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;
/**
 * dp[n]��ʾ����Ϊn�����ķ�����
 * ���������������һ�κ�ɫ�ͺ�ɫ֮��ʣ��ĳ��ȵķ�������
 * ��dp[n]+=dp[n-i-j-1]������i�Ǻ�ɫ�ĳ��ȣ�j�Ǻ�ɫ�ĳ��ȣ�1�������ɫ����Ҫ��1��
 */
long long dp[51];
long long dfs(int n)
{
    if (n < 3) return 1;
    if (dp[n]) return dp[n];
    // ɶҲ����
    dp[n] = 1;
    for (int i = 0; i <= n - 3; i++)
        for (int j = 3; i + j <= n; j++)
            dp[n] += dfs(n - i - j - 1);
    return dp[n];
}
int main()
{
    cout << dfs(50) << endl;
    return 0;
}
