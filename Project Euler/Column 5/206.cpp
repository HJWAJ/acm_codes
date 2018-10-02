#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
bool ok(long long n)
{
    n = n * n;
    n /= 100;
    int tmp, i = 9;
    while (n)
    {
        tmp = n % 100;
        if (tmp % 10 != i) return 0;
        n /= 100;
        i--;
    }
    if (i) return 0;
    return 1;
}
int main()
{
    for (long long n = 1000000000LL; n <= 2000000000LL; n += 10)
        if (ok(n))
        {
            cout << n << endl;
            break;
        }
    return 0;
}
