#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
long long fact = 3628800LL;
int count_one(int x)
{
    int cnt = 0;
    while (x)
    {
        if (x & 1) cnt++;
        x >>= 1;
    }
    return cnt;
}
int main()
{
    long long sum = 0;
    for (int i = 0; i < (1 << 20); i++)
    {
        if (count_one(i) == 10)
        {
            bool flag = true;
            for (int j = 0; j < 10; j++)
                if ((i & (1 << (j * 2 + 1))) && !(i & (1 << (j * 2))))
                    flag = false;
            if (!flag) continue;
            int digit_sum = 0;
            for (int j = 0; j < 20; j++)
                if (i & (1 << j))
                    digit_sum += j / 2;
            // 奇偶数位差是11的倍数且不相等
            if ((90 - digit_sum - digit_sum) % 11 == 0)
            {
                // 奇数
                long long tmp1 = 0;
                // 2个0
                if ((i & 3) == 3)
                {
                    int double_cnt = 1, single_cnt = 0;
                    for (int j = 1; j < 10; j++)
                    {
                        if (((i & (3 << (j << 1))) >> (j << 1)) == 3) double_cnt++;
                        else if (((i & (3 << (j << 1))) >> (j << 1)) == 1) single_cnt++;
                    }
                    tmp1 = fact / 10 / (1 << double_cnt) * single_cnt + fact / 10 / (1 << (double_cnt - 1)) * (double_cnt - 1);
                }
                // 1个0
                else if (i & 1)
                {
                    int double_cnt = 0, single_cnt = 1;
                    for (int j = 1; j < 10; j++)
                    {
                        if (((i & (3 << (j << 1))) >> (j << 1)) == 3) double_cnt++;
                        else if (((i & (3 << (j << 1))) >> (j << 1)) == 1) single_cnt++;
                    }
                    tmp1 = fact / 10 / (1 << double_cnt) * (single_cnt - 1) + fact / 10 / (1 << (double_cnt - 1)) * double_cnt;
                }
                else
                {
                    tmp1 = fact;
                    for (int j = 0; j < 10; j++)
                        if ((i & (1 << (j * 2))) && (i & (1 << (j * 2 + 1))))
                            tmp1 /= 2;
                }
                // 偶数
                long long tmp2 = fact;
                for (int j = 0; j < 10; j++)
                    if (!(i & (1 << (j * 2))) && !(i & (1 << (j * 2 + 1))))
                        tmp2 /= 2;
                sum += tmp1 * tmp2;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
