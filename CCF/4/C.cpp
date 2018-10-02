#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
const int N = 5005;
struct GP
{
    bool buy;
    double price;
    int tot;
    void read(bool b)
    {
        buy = b;
        scanf("%lf%d", &price, &tot);
    }
}gp[N];
map<double, long long> buy, sell;
set<double> price;
int main()
{
    char op[10];
    //freopen("4.txt", "r", stdin);
    for (int line = 1; ~scanf("%s", op); line++)
    {
        if (op[0] == 'c')
        {
            int x;
            scanf("%d", &x);
            (gp[x].buy ? buy : sell)[gp[x].price] -= gp[x].tot;
        }
        else
        {
            gp[line].read(op[0] == 'b');
            price.insert(gp[line].price);
            (gp[line].buy ? buy : sell)[gp[line].price] += gp[line].tot;
        }
    }
    long long bsum = 0;
    for (map<double, long long>::iterator i = buy.begin(); i != buy.end(); i++)bsum += i->second;
    long long ssum = 0;
    double ansprice = 0;
    long long anstot = 0;
    for (set<double>::iterator i = price.begin(); i != price.end(); i++)
    {
        if (!(sell[*i] || buy[*i]))continue;
        ssum += sell[*i];
        long long x = min(ssum, bsum);
        if (x >= anstot)
        {
            anstot = x;
            ansprice = *i;
        }
        bsum -= buy[*i];
    }
    printf("%.2f %lld\n", ansprice, anstot);
    return 0;
}
