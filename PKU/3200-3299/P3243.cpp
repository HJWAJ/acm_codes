#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<queue>
#include<string>
#include<vector>
using namespace std;

const int hashmax = 655373;
bool hashtable[hashmax];
int data[hashmax], map[hashmax];

unsigned int hash (unsigned int a) { return (a ^ 0xA5A5A5A5) % hashmax; }
void hashinit (void) { memset(hashtable, 0, sizeof(hashtable)); }
void add (int aj, int j)
{
    int idx = hash(aj);
    while (hashtable[idx] && data[idx] != aj) { idx++; if (idx == hashmax) idx = 0; }
    hashtable[idx] = true;
    data[idx] = aj, map[idx] = j;
}
int query (int aj)
{
    int idx = hash(aj);
    while (hashtable[idx])
    {
        if (data[idx] == aj) return map[idx];
        idx++; if (idx == hashmax) idx = 0;
    } return -1;
}
int gcd (int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int himod (int a, int b, int m)
{
    int ans = 1, p = a;
    while (b)
    {
        if (b & 1) ans = (__int64)ans * p % m;
        p = (__int64)p * p % m; b >>= 1;
    } return ans;
}
int babystep (int b, int p, int n)
{
    int aj, step, t, ans;
    int m = (int)ceil(sqrt((double)p));
    b %= p, n %= p;
    hashinit();
    aj = n; for (int j = 0; j <= m; j++)
    {
        add(aj, j);
        aj = ((__int64)aj * b) % p;
    }
    step = himod(b, m, p);
    aj = 1, ans = -1;
    for (int i = 1; i * m <= p; i++)
    {
        aj = ((__int64)aj * step) % p;
        t = query(aj);
        if (t != -1) { ans = i * m - t; break; }
    } return ans;
}
int main ()
{
    int p, b, n, si, i, g;
    char *invalid = "No Solution";
    while (1)
    {
        scanf("%d %d %d", &b, &p, &n);
        if (p == 0 && b == 0 && n == 0) break;
        b %= p; n %= p;
        if (n == 1)
        {
            if (b == 0) printf("%s\n", invalid);
            else printf("0\n");
            continue;
        }
        else if (b == 0 && n == 0)
        {
            printf("1\n");
            continue;
        }
        si = 1; for (i = 1; i <= 40; i++)
        {
            si = (__int64)si * b % p;
            if (si == n) break;
        }
        if (si == n)
        {
            printf("%d\n", i);
            continue;
        }
        g = gcd(n, p);
        if (gcd(p / g, b) > 1)
        {
            printf("%s\n", invalid);
            continue;
        }
        while ((i = gcd(p, b)) > 1) p /= i;
        b %= p, n %= p;
        si = babystep(b, p, n);
        if (si < 0)
        {
            printf("%s\n", invalid);
            continue;
        }
        else if (si <= 40)
        {
            i = babystep(b, p, 1);
            while (si <= 40) si += i;
        }
        if (himod(b, si, p) == n) printf("%d\n", si);
        else printf("%s\n", invalid);
    }
    return 0;
}
