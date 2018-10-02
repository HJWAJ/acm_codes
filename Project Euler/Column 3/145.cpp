#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
int rev(int n)
{
    int res = 0;
    while (n)
    {
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}
bool ok(int n)
{
    while(n)
    {
        if (!(n & 1)) return false;
        n /= 10;
    }
    return true;
}
int main()
{
    int cnt = 0;
    for (int i = 1; i < 1000000000; i++)
    {
        if (i % 10 == 0) continue;
        if (ok(i + rev(i))) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
