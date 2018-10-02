#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const char s[5][40] = {
    "###   # ### ### # # ### ### ### ### ###",
    "# #   #   #   # # # #   #   # # # # # #",
    "# #   # ### ### ### ### ### # # ### ###",
    "# #   # #     #   #   # # #   # # #   #",
    "###   # ### ###   # ### ###   # ### ###",
};
int prime[4000000];
bool bo[25000001];
int prime_table()
{
    int i, j, flag=0;
    memset(bo, 0, sizeof(bo));
    bo[0] = bo[1] = 1;
    for (i = 2; i <= 5000; i++)
        if(!bo[i])
        {
            j = i * i;
            for (; j <= 25000000; j += i) bo[j] = 1;
        }
    for (i = 0; i <= 25000000; i++)
        if(!bo[i]) prime[flag++] = i;
    return flag;
}
int diff(int a, int b)
{
    int left_a = a * 4, left_b = b * 4, top = 0;
    int cnt = 0;
    if (a == -1 && b == -1) return 0;
    if (a == -1) return diff(b, a);
    if (b == -1)
    {
        if (s[top][left_a + 1] == '#') cnt++;
        if (s[top + 1][left_a] == '#') cnt++;
        if (s[top + 3][left_a] == '#') cnt++;
        if (s[top + 2][left_a + 1] == '#') cnt++;
        if (s[top + 4][left_a + 1] == '#') cnt++;
        if (s[top + 1][left_a + 2] == '#') cnt++;
        if (s[top + 3][left_a + 2] == '#') cnt++;
    }
    else
    {
        if (s[top][left_a + 1] == '#' ^ s[top][left_b + 1] == '#') cnt++;
        if (s[top + 1][left_a] == '#' ^ s[top + 1][left_b] == '#') cnt++;
        if (s[top + 3][left_a] == '#' ^ s[top + 3][left_b] == '#') cnt++;
        if (s[top + 2][left_a + 1] == '#' ^ s[top + 2][left_b + 1] == '#') cnt++;
        if (s[top + 4][left_a + 1] == '#' ^ s[top + 4][left_b + 1] == '#') cnt++;
        if (s[top + 1][left_a + 2] == '#' ^ s[top + 1][left_b + 2] == '#') cnt++;
        if (s[top + 3][left_a + 2] == '#' ^ s[top + 3][left_b + 2] == '#') cnt++;
    }
    return cnt;
}
int lightA(int n)
{
    int res = 0, nn = 0;
    while (n >= 10)
    {
        while(n)
        {
            res += diff(-1, n % 10);
            res += diff(n % 10, -1);
            nn += n % 10;
            n /= 10;
        }
        n = nn;
        nn = 0;
    }
    res += diff(-1, n);
    res += diff(n, -1);
    return res;
}
int lightB(int n)
{
    int res = 0, n_last, n_cur = n, n_prev;
    while (n)
    {
        res += diff(-1, n % 10);
        n /= 10;
    }
    while (n_cur >= 10)
    {
        n_last = n_cur;
        n_prev = 0;
        while (n_cur)
        {
            n_prev += n_cur % 10;
            n_cur /= 10;
        }
        n_cur = n_prev;
        while (n_last)
        {
            if (n_prev) res += diff(n_last % 10, n_prev % 10);
            else res += diff(n_last % 10, -1);
            n_last /= 10;
            n_prev /= 10;
        }
    }
    res += diff(n_cur, -1);
    return res;
}
int main()
{
    prime_table();
    long long ans = 0;
    for (int i = 0; ; i++)
    {
        if (prime[i] > 10000000 && prime[i] < 20000000)
            ans += lightA(prime[i]) - lightB(prime[i]);
        if (prime[i] > 20000000)
            break;
    }
    cout << ans << endl;
    return 0;
}
