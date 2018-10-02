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
#include <queue>
using namespace std;
int main()
{
    int a, b;
    double ans, val;
    while (scanf("%d%d", &a, &b) != EOF)
    {
        ans = 1e9;
        for (int i = 1; i <= b; i++)
        {
            val = i * 1.0 * a / b + 0.5;
            val = int(val);
            if (fabs(val / i - a * 1.0 / b) < ans)
            {
                ans = fabs(val / i - a * 1.0 / b);
                printf("%.0lf/%d\n", val, i);
            }
        }
        puts("");
    }
    return 0;
}
