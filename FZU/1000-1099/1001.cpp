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
bool bo[1000005];
int main()
{
    int n, ans, a;
    while (scanf("%d", &n) != EOF)
    {
        memset(bo, 0, sizeof(bo));
        while (n--)
        {
            scanf("%d", &a);
            if (!bo[a]) bo[a] = 1;
            else ans = a;
        }
        printf("%d\n", ans);
    }
    return 0;
}
