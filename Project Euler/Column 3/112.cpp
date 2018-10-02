#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
bool ok(int n)
{
    int nn = n, tmp = 10;
    while (n)
    {
        if (n % 10 > tmp)
            break;
        tmp = n % 10;
        n /= 10;
    }
    if (n == 0)
        return true;
    n = nn;
    tmp = 0;
    while (n)
    {
        if (n % 10 < tmp)
            break;
        tmp = n % 10;
        n /= 10;
    }
    if (n == 0)
        return true;
    return false;
}
int main()
{
    int i, cnt1 = 0, cnt2 = 0;
    for (i = 1; ; i++)
    {
        if (!ok(i))
            cnt1++;
        cnt2++;
        if (cnt1 * 1.0 / cnt2 >= 0.99 - (1e-12))
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
