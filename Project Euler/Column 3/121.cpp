#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
// 枚举每种情况，1是取红球，1在从右到左第i位的概率是MAX - i
const int MAX = 15;
int main()
{
    long long numerator = 0, denominator = 1, tmp, ano_numerator;
    int i, j, cnt_one;
    for (i = 0; i < (1 << MAX); i++)
    {
        cnt_one = 0;
        tmp = 1;
        for (j = 0; j < MAX; j++)
            if (i & (1 << j))
                cnt_one++;
        if (cnt_one < (MAX + 1) / 2)
        {
            for (j = 0; j < MAX; j++)
                if (i & (1 << j))
                    tmp *= (MAX - j);
            numerator += tmp;
        }
    }
    for (i = 1; i <= MAX + 1; i++)
        denominator *= i;
    ano_numerator = denominator - numerator;
    cout << ano_numerator / numerator + 1 << endl;
    return 0;
}
