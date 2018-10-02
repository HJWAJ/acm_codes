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
const double eps = 1e-6;
int main()
{
    double length, aim;
    int cnt;
    while (scanf("%lf", &aim) && fabs(aim) > eps)
    {
        cnt = 0;
        length = 0;
        for (int i = 2; length < aim; i++)
        {
            length += 1.0 / i;
            cnt++;
        }
        printf("%d card(s)\n", cnt);
    }
    return 0;
}
