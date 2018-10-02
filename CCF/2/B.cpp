#include <iostream>
using namespace std;
struct window {
    int x1, y1, x2, y2, id;
} w[15];
void rearrange(int cnt, int n) {
    w[n] = w[cnt];
    for (int i = cnt; i < n - 1; i++) {
        w[i] = w[i + 1];
    }
    w[n - 1] = w[n];
}
int main()
{
    int n, m, x, y;
    bool flag;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d%d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
            w[i].id = i + 1;
        }
        while (m--) {
            flag = false;
            scanf("%d%d", &x, &y);
            for (int i = n - 1; i >= 0; i--) {
                if (x >= w[i].x1 && x <= w[i].x2 && y >= w[i].y1 && y <= w[i].y2) {
                    flag = true;
                    printf("%d\n", w[i].id);
                    rearrange(i, n);
                    break;
                }
            }
            if (!flag) {
                puts("IGNORED");
            }
        }
    }
    return 0;
}