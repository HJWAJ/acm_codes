#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[55];
bool inc[26];
bool incb[26];
char ans[55][55];
void init() {
    memset(inc, 0, sizeof(inc));
    memset(incb, 0, sizeof(incb));
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == ':') continue;
        else {
            inc[s[i] - 'a'] = true;
            if (i + 1 < len && s[i + 1] == ':') {
                incb[s[i] - 'a'] = true;
            }
        }
    }
}
int main()
{
    int num, t, tt, len, i, cur, j;
    while (scanf("%s", s) != EOF) {
        init();
        scanf("%d", &t);
        gets(s);
        tt = 0;
        while (t--) {
            tt++;
            num = 0;
            gets(s);
            memset(ans, 0, sizeof(ans));
            len = strlen(s);
            for (i = 0; i < len; i++) {
                if (s[i] == ' ') {
                    break;
                }
            }
            i++;
            while (i < len) {
                if (s[i] != '-') {
                    break;
                }
                if (i == len - 1) {
                    break;
                }
                if (i + 2 < len && s[i + 2] != ' ') {
                    break;
                }
                if (!(s[i + 1] >= 'a' && s[i + 1] <= 'z' && inc[s[i + 1] - 'a'])) {
                    break;
                }
                if (incb[s[i + 1] - 'a'] && i + 3 >= len) {
                    break;
                }
                cur = -1;
                for (j = 0; j < num; j++) {
                    if (ans[j << 1][1] == s[i + 1]) {
                        cur = j;
                        break;
                    }
                }
                if (cur == -1) {
                    cur = num++;
                    ans[cur << 1][0] = '-';
                    ans[cur << 1][1] = s[i + 1];
                }
                i += 3;
                if (incb[s[i - 2] - 'a'] && i < len) {
                    for (j = i; j < len && ((s[j] >= 'a' && s[j] <= 'z') || s[j] == '-' || (s[j] >= '0' && s[j] <= '9')); j++) {
                        ans[(cur << 1) + 1][j - i] = s[j];
                    }
                    ans[(cur << 1) + 1][j - i] = '\0';
                    i = j + 1;
                }
            }
            for (i = 0; i < num - 1; i++) {
                for (j = 0; j < num - 1 - i; j++) {
                    if (ans[j << 1][1] > ans[(j + 1) << 1][1]) {
                        strcpy(s, ans[j << 1]);
                        strcpy(ans[j << 1], ans[(j + 1) << 1]);
                        strcpy(ans[(j + 1) << 1], s);
                        strcpy(s, ans[(j << 1) + 1]);
                        strcpy(ans[(j << 1) + 1], ans[((j + 1) << 1) + 1]);
                        strcpy(ans[((j + 1) << 1) + 1], s);
                    }
                }
            }
            printf("Case %d:", tt);
            for (i = 0; i < num; i++) {
                printf(" %s", ans[i << 1]);
                if (incb[ans[i << 1][1] - 'a'] && strlen(ans[(i << 1) + 1]) > 0) {
                    printf(" %s", ans[(i << 1) + 1]);
                }
            }
            puts("");
        }
    }
    return 0;
}