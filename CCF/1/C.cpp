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
int h[1005];
int main()
{
    int n, mmax, tmp, last;
    while (scanf("%d", &n) != EOF)
    {
        mmax = 0;
        for (int i = 0; i < n; i++) scanf("%d", h + i);
        for (int i = 0; i < n; i++)
        {
            last = h[i];
            for (int j = i; j < n; j++)
            {
                if (h[j] < last) last = h[j];
                tmp = (j - i + 1) * last;
                if (tmp > mmax) mmax = tmp;
            }
        }
        printf("%d\n", mmax);
    }
    return 0;
}