#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
long long cnt[2][37];
long long four_nine = 262144;
long long six_six = 46656;
void dfs(long long cnt[], int faces, int dices, int sum)
{
    if (dices == 0)
    {
        cnt[sum]++;
        return;
    }
    else
    {
        for (int i = 1; i <= faces; i++)
            dfs(cnt, faces, dices - 1, sum + i);
    }
}
int main()
{
    dfs(cnt[0], 4, 9, 0);
    dfs(cnt[1], 6, 6, 0);
    long long sum = 0;
    for (int i = 1; i <= 36; i++)
        for (int j = 1; j < i; j++)
            sum += cnt[0][i] * cnt[1][j];
    printf("%.7lf\n", sum * 1.0 / six_six / four_nine);
    return 0;
}
