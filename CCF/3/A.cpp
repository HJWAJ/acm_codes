#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int a[1005];
int main()
{
    int n, cnt;
    while (scanf("%d", &n) != EOF)
    {
        cnt = 0;
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] - a[j] == 1 || a[i] - a[j] == -1)
                    cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}