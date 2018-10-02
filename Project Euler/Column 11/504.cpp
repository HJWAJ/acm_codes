#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int n = 100;
inline int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
inline int sqr(int n)
{
    return n * n;
}
inline bool is_sqr(int n)
{
    int sq = sqrt(n * 1.0);
    return sqr(sq) == n || sqr(sq + 1) == n || sqr(sq - 1) == n;
}
inline int calc(int a, int b, int c, int d)
{
    int area = (a + c) * (b + d) / 2;
    int cnt_line = gcd(a, b) + gcd(b, c) + gcd(c, d) + gcd(d, a);
    return area + 1 - cnt_line / 2;
}
int main()
{
    int num = 0;
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            for (int c = 1; c <= n; c++)
                for (int d = 1; d <= n; d++)
                    if (is_sqr(calc(a, b, c, d)))
                        num++;
    cout << num << endl;
    return 0;
}
