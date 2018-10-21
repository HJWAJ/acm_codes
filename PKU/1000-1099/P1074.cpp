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
map<string, int> vars;
int var_cnt;
bool isChar(char ch) {
    return ch >= 'a' && ch <= 'z';
}
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}
bool isVarChar(char ch) {
    return isChar(ch) || isDigit(ch) || ch == '_';
}
int atoi(char s[]) {
    int res = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}
char s[1005], tmp[3][1005];
struct Ins {
    int op; // mov:0; add:1, sub:2
    int src;
    int dest;
    int src_type; // 0-var, 1-num
};
Ins prog[2][1005];
int prog_len[2];
int prog_id = 0;
void init() {
    prog_id = 0;
    prog_len[0] = prog_len[1] = 0;
    vars.clear();
    vars["_r11"] = 0;
    vars["_r12"] = 1;
    vars["_r21"] = 2;
    vars["_r22"] = 3;
}
int map_id(char s[]) {
    if (vars.find(s) == vars.end()) {
        int val = vars.size();
        vars[s] = val;
    }
    return vars[s];
}
void analyse(char s[], int len) {
    char* s1 = strstr(s, ":");
    char* s2 = strstr(s, "+");
    char op = '+';
    if (!s2) {
        s2 = strstr(s, "-");
        op = '-';
    }
    strncpy(tmp[0], s, s1 - s);
    tmp[0][s1 - s] = 0;
    strncpy(tmp[1], s1 + 2, s2 - (s1 + 2));
    tmp[1][s2 - (s1 + 2)] = 0;
    strncpy(tmp[2], s2 + 1, s + len - (s2 + 1));
    tmp[2][s + len - (s2 + 1)] = 0;

    prog[prog_id][prog_len[prog_id]].op = 0;
    prog[prog_id][prog_len[prog_id]].dest = (!prog_id ? 0 : 2);
    if (isDigit(tmp[1][0])) {
        prog[prog_id][prog_len[prog_id]].src = atoi(tmp[1]);
        prog[prog_id][prog_len[prog_id]++].src_type = 1;
    } else {
        prog[prog_id][prog_len[prog_id]].src = map_id(tmp[1]);
        prog[prog_id][prog_len[prog_id]++].src_type = 0;
    }

    prog[prog_id][prog_len[prog_id]].op = 0;
    prog[prog_id][prog_len[prog_id]].dest = (!prog_id ? 1 : 3);
    if (isDigit(tmp[2][0])) {
        prog[prog_id][prog_len[prog_id]].src = atoi(tmp[2]);
        prog[prog_id][prog_len[prog_id]++].src_type = 1;
    } else {
        prog[prog_id][prog_len[prog_id]].src = map_id(tmp[2]);
        prog[prog_id][prog_len[prog_id]++].src_type = 0;
    }

    prog[prog_id][prog_len[prog_id]].op = (op == '+' ? 1 : 2);
    prog[prog_id][prog_len[prog_id]].dest = (!prog_id ? 0 : 2);
    prog[prog_id][prog_len[prog_id]].src = (!prog_id ? 1 : 3);
    prog[prog_id][prog_len[prog_id]++].src_type = 0;

    prog[prog_id][prog_len[prog_id]].op = 0;
    prog[prog_id][prog_len[prog_id]].dest = map_id(tmp[0]);
    prog[prog_id][prog_len[prog_id]++].src = (!prog_id ? 0 : 2);
}
int trim(char s[], int len) {
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] != ' ' && s[i] != '\t') {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
    return j;
}
void input() {
    while (gets(s)) {
        int len = strlen(s);
        if (len == 0) continue;
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
        }
        len = trim(s, len);
        if (!strcmp(s, "end")) {
            break;
        }
        analyse(s, len);
    }
    prog_id = 1;
    while (gets(s)) {
        int len = strlen(s);
        len = trim(s, len);
        if (len == 0) continue;
        for (int i = 0; i < len; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
        }
        if (!strcmp(s, "end")) {
            break;
        }
        analyse(s, len);
    }
    var_cnt = vars.size();
    /*
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < prog_len[i]; j++) {
            printf("%d %d %d\n", prog[i][j].op, prog[i][j].dest, prog[i][j].src);
        }
    puts("---------------------");
    */
}

// 程序1执行到指令i，程序2执行到指令j的概率
double p[125][125];
void calc_p() {
    for (int i = 0; i <= prog_len[0]; i++) {
        for (int j = 0; j <= prog_len[1]; j++) {
            p[i][j] = 0;
        }
    }
    for (int i = 0; i <= prog_len[0]; i++) {
        for (int j = 0; j <= prog_len[1]; j++) {
            if (i == 0 && j == 0) {
                p[i][j] = 1;
            } else if (i == 0) {
                p[i][j] = p[i][j - 1] / (i == prog_len[0] ? 1 : 2);
            } else if (j == 0) {
                p[i][j] = p[i - 1][j] / (j == prog_len[1] ? 1 : 2);
            } else {
                p[i][j] = p[i - 1][j] / (j == prog_len[1] ? 1 : 2) + p[i][j - 1] / (i == prog_len[0] ? 1 : 2);
            }
        }
    }
}

// 程序1执行到指令i，程序2执行到指令j的各值期望
double dp[105][105][15];
double tmp_res[15];
void calc_ins(int prog_id, int ins_id, int from_i, int from_j) {
    Ins ins = prog[prog_id][ins_id];
    double src;
    double dest;
    for (int i = 0; i < var_cnt; i++) {
        tmp_res[i] = dp[from_i][from_j][i];
    }
    if (ins.src_type) {
        src = ins.src;
    } else {
        src = tmp_res[ins.src];
    }
    if (ins.op == 0) {
        dest = src;
    } else if (ins.op == 1) {
        dest = tmp_res[ins.dest] + src;
    } else {
        dest = tmp_res[ins.dest] - src;
    }
    tmp_res[ins.dest] = dest;
}
void calc() {
    for (int i = 0; i <= prog_len[0]; i++)
        for (int j = 0; j <= prog_len[1]; j++)
            for (int k = 0; k < var_cnt; k++)
                dp[i][j][k] = 0;
    for (int i = 0; i <= prog_len[0]; i++) {
        for (int j = 0; j <= prog_len[1]; j++) {
            if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                calc_ins(1, j - 1, i, j - 1);
                for (int k = 0; k < var_cnt; k++) {
                    dp[i][j][k] = tmp_res[k];
                }
            } else if (j == 0) {
                calc_ins(0, i - 1, i - 1, j);
                for (int k = 0; k < var_cnt; k++) {
                    dp[i][j][k] = tmp_res[k];
                }
            } else {
                calc_ins(1, j - 1, i, j - 1);
                for (int k = 0; k < var_cnt; k++) {
                    dp[i][j][k] = tmp_res[k] * p[i][j - 1] / (i == prog_len[0] ? 1 : 2);
                }
                calc_ins(0, i - 1, i - 1, j);
                for (int k = 0; k < var_cnt; k++) {
                    dp[i][j][k] += tmp_res[k] * p[i - 1][j] / (j == prog_len[1] ? 1 : 2);
                }
                for (int k = 0; k < var_cnt; k++) {
                    dp[i][j][k] /= p[i][j];
                }
            }
        }
    }
}
void solve() {
    init();
    input();
    calc_p();
    calc();
    int m = prog_len[0];
    int n = prog_len[1];
    /*
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < var_cnt; k++)
                printf("%.4lf\n", dp[i][j][k]);
            puts("");
        }
    puts("-----------------------");
    */
    int index[15], i = 0;
    for (map<string, int>::iterator it = vars.begin(); it != vars.end(); it++) {
        if ((it->first)[0] != '_') {
            index[i++] = it->second;
        }
    }
    for (int k = 4; k < var_cnt; k++) {
        printf("%.4lf\n", dp[m][n][index[k - 4]]);
    }
    puts("");
}
int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
