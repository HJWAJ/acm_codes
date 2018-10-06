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
vector<int> g[60][60];
int g_cnt[60][60];
int v_cnt[60];
int path[100005];
int path_top;
int start;
bool cmp(const int &a, const int &b) {
    return a > b;
}
int init() {
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            g[i][j].clear();
        }
    }
    memset(g_cnt, 0, sizeof(g_cnt));
    memset(v_cnt, 0, sizeof(v_cnt));
    path_top = 0;

    int u, v, e, cnt = 0;
    while (scanf("%d%d", &u, &v) && (u || v)) {
        scanf("%d", &e);
        if (cnt == 0) {
            start = u;
        }
        cnt++;
        g[u][v].push_back(e);
        g[v][u].push_back(e);
        g_cnt[u][v]++;
        g_cnt[v][u]++;
        v_cnt[u]++;
        v_cnt[v]++;
    }
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            sort(g[i][j].begin(), g[i][j].end(), cmp);
        }
    }
    return cnt;
}
bool test() {
    for (int i = 1; i < 60; i++) {
        if (v_cnt[i] & 1) {
            return false;
        }
    }
    return true;
}
void travel(int cur) {
    for (int i = 0; i < 60; i++) {
        if (g_cnt[cur][i]) {
            g_cnt[cur][i]--;
            g_cnt[i][cur]--;
            travel(i);
        }
    }
    path[path_top++] = cur;
}
void travel() {
    travel(start);
    int u = path[path_top - 1];
    int v;
    for (int i = path_top - 2; i >= 0; i--) {
        v = path[i];
        printf("%d ", g[u][v][g[u][v].size() - 1]);
        g[u][v].pop_back();
        g[v][u].pop_back();
        u = v;
    }
    puts("");
}
int main() {
    while (true) {
        int e_cnt = init();
        if (e_cnt == 0) {
            break;
        }
        if (test()) {
            travel();
        } else {
            puts("Round trip does not exist.");
        }
    }
    return 0;
}
