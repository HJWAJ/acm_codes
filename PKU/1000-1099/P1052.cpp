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
int dir[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
int n;
char s[6][25][25];
bool g[25][25][25];
void rotate(int index) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[index + 3][j][n - i - 1] = s[index][i][j];
        }
    }
}
void print_g() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                printf("%d", g[i][j][k] ? 1 : 0);
            }
            puts("");
        }
        puts("");
    }
}
void dfs(int m, int n, int k) {
    if (!g[m][n][k]) return;
    //print_g();
    //getchar();
    g[m][n][k] = false;
    for (int i = 0; i < 6; i++) {
        dfs(m + dir[i][0], n + dir[i][1], k + dir[i][2]);
    }
}
bool test_valid() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool ok = false;
            if (s[3][i][j] == 'X') {
                for (int k = 1; k <= n; k++) {
                    if (g[i + 1][j + 1][k]) {
                        ok = true;
                    }
                }
                if (!ok) {
                    return false;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool ok = false;
            if (s[4][i][j] == 'X') {
                for (int k = 1; k <= n; k++) {
                    if (g[k][j + 1][i + 1]) {
                        ok = true;
                    }
                }
                if (!ok) {
                    return false;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool ok = false;
            if (s[5][i][j] == 'X') {
                for (int k = 1; k <= n; k++) {
                    if (g[j + 1][k][i + 1]) {
                        ok = true;
                    }
                }
                if (!ok) {
                    return false;
                }
            }
        }
    }
    return true;
}
bool test_connect() {
    memset(g, 0, sizeof(g));
    bool has_block = false;
    int start_i, start_j, start_k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (s[3][i][j] == 'X' && s[4][k][j] == 'X' && s[5][k][i] == 'X') {
                    g[i + 1][j + 1][k + 1] = true;
                    if (!has_block) {
                        has_block = true;
                        start_i = i + 1;
                        start_j = j + 1;
                        start_k = k + 1;
                    }
                }
            }
        }
    }
    if (!test_valid()) {
        return false;
    }
    //print_g();
    if (!has_block) {
        return true;
    }
    dfs(start_i, start_j, start_k);
    //print_g();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (g[i + 1][j + 1][k + 1]) {
                    return false;
                }
            }
        }
    }
    return true;
}
void copy(int index) {
    for (int i = 0; i < n; i++) {
        strcpy(s[index][i], s[index + 3][i]);
    }
}
int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int t = 0;
    while (scanf("%d", &n) && n) {
        t++;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%s", s[i][j]);
            }
        }
        bool ok = false;
        for (int i = 0; i < 4; i++) {
            rotate(0);
            copy(0);
            for (int j = 0; j < 4; j++) {
                rotate(1);
                copy(1);
                for (int k = 0; k < 4; k++) {
                    rotate(2);
                    copy(2);
                    if (test_connect()) {
                        ok = true;
                        goto end;
                    }
                }
            }
        }
        end:
        printf("Data set %d: %s\n", t, ok ? "Valid set of patterns" : "Impossible combination");
    }
    return 0;
}