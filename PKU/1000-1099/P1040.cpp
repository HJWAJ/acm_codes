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
int station_cap[10];
struct Station {
    int start;
    int end;
    int num;
    int earning;
    int max_earn;
    bool operator < (const Station b) const {
        if (earning > b.earning) {
            return true;
        } else if (earning == b.earning) {
            if (start < b.start) {
                return true;
            } else if (start == b.start) {
                if (end < b.end) {
                    return true;
                } else if (end == b.end) {
                    if (num < b.num) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
} station[100];
int cap, m, n;
int earning;
int max_earn;

int try_order(int cur) {
    bool ok = true;
    for (int i = station[cur].start; i < station[cur].end; i++) {
        station_cap[i] += station[cur].num;
        if (station_cap[i] > cap) {
            ok = false;
            for (int j = station[cur].start; j <= i; j++) {
                station_cap[j] -= station[cur].num;
            }
            break;
        }
    }
    if (!ok) {
        return -1;
    }
    return station[cur].earning;
}

void dfs(int cur) {
    if (station[cur].earning == 0) {
        return;
    }
    if (cur > 0 && station[n - 1].max_earn - station[cur - 1].max_earn + earning < max_earn) {
        return;
    }
    int order = try_order(cur);
    if (order > 0) {
        earning += order;
        //cout << "order " << cur << " earning " << order << " sum " << earning << endl;
        if (earning > max_earn) {
            max_earn = earning;
        }
    }
    for (int i = cur; i < n; i++) {
        dfs(i + 1);
    }
    if (order > 0) {
        earning -= order;
        //cout << "return " << cur << " earning " << order << " sum " << earning << endl;
        for (int j = station[cur].start; j < station[cur].end; j++) {
            station_cap[j] -= station[cur].num;
        }
    }
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (scanf("%d%d%d", &cap, &m, &n) && (cap || m || n)) {
        memset(station, 0, sizeof(station));
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &station[i].start, &station[i].end, &station[i].num);
            if (station[i].num > cap) {
                station[i].num = station[i].earning = 0;
            } else {
                station[i].earning = (station[i].end - station[i].start) * station[i].num;
            }
        }
        sort(station, station + n);
        station[0].max_earn = station[0].earning;
        for (int i = 1; i < n; i++) {
            station[i].max_earn = station[i - 1].max_earn + station[i].earning;
        }
        memset(station_cap, 0, sizeof(station_cap));
        earning = max_earn = 0;
        for (int i = 0; i < n; i++) {
            dfs(i);
        }
        printf("%d\n", max_earn);
    }
    return 0;
}
