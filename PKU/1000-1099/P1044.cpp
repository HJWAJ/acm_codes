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
#include <vector>
using namespace std;
int y[10005];
int main() {
    int t = 0;
    int n, a, b, c, d;
    while (scanf("%d", &n) && n) {
        t++;
        bool unknown = false;
        int ans = -1;
        memset(y, 0, sizeof(y));
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            bool satisfy = false;
            if (unknown) continue;
            d = c - b;
            while (a < 10000) {
                y[a]++;
                if (y[a] == i + 1) {
                    satisfy = true;
                }
                if (y[a] == n) {
                    ans = a;
                    break;
                }
                a += d;
            }
            if (!satisfy) unknown = true;
        }
        printf("Case #%d:\n", t);
        if (unknown) {
            puts("Unknown bugs detected.");
        } else {
            printf("The actual year is %d.\n", ans);
        }
        puts("");
    }
    return 0;
}
