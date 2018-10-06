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
// 题意：有n个名字和昵称，E表示名字进入房间，M表示昵称发信息，L表示名字离开房间
// 需要求出名字和昵称的对应关系

// 先假设每个名字和所有昵称都对应，然后去掉不可能的
// 然后匈牙利算法求一遍最大匹配，但此时的匹配不一定是唯一匹配
// 需要确定唯一匹配，可以删除当前已匹配的边，如果匹配数变少，则能够确定这条边是正确匹配
int n;
char tmp[25];
string criminals[25];
string userids[25];
map<string, int> criminal_id;
map<string, int> userid_id;
map<string, string> match;
int cnt;
int g[25][25];
bool in[25];

int vis[25], link[25], link_cp[25];
int dfs(int u)
{
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&g[u][i]==1)
        {
            vis[i]=1;
            if(link[i]==-1||dfs(link[i]))
            {
                link[i]=u;
                return 1;
            }
        }
    }
    return 0;
}

int Hungry()
{
    memset(link,-1,sizeof(link));
    int ans=0;
    for(int i=0;i<n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                ans++;
        }
    return ans;
}

void print() {
    for (int i = 0; i < n; i++) printf("%s ", criminals[i].c_str());
    puts("");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", g[i][j]);
        }
        puts("");
    }
    for (map<string, string>::iterator it = match.begin(); it != match.end(); it++) {
        string name = it->first;
        string id = it->second;
        if (id.length() == 0) {
            id = "???";
        }
        printf("%s:%s\n", name.c_str(), id.c_str());
    }
    puts("ok");
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        userids[i] = tmp;
        userid_id[userids[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = 1;
        }
    }
    while (scanf("%s", tmp)) {
        char ins = tmp[0];
        if (ins == 'Q') break;
        scanf("%s", tmp);
        string s = tmp;
        if (ins == 'E' || ins == 'L') {
            if (criminal_id.find(s) == criminal_id.end()) {
                criminals[cnt] = s;
                criminal_id[s] = cnt++;
            }
        }
        if (ins == 'E') {
            in[criminal_id[s]] = 1;
        } else if (ins == 'L') {
            in[criminal_id[s]] = 0;
        } else if (ins == 'M') {
            for (int i = 0; i < n; i++) {
                if (!in[i]) {
                    g[i][userid_id[s]] = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        match[criminals[i]] = "";
    }

    //print();

    int ans = Hungry();
    for (int i = 0; i < n; i++) {
        link_cp[i] = link[i];
    }

    //for(int i = 0; i < n; i++) printf("%d ", link_cp[i]);
    //puts("");

    for (int i = 0; i < n; i++) {
        if (link_cp[i] == -1) continue;
        g[link_cp[i]][i] = 0;
        if (ans != Hungry()) {
            match[criminals[link_cp[i]]] = userids[i];
        }
        g[link_cp[i]][i] = 1;
    }
    for (map<string, string>::iterator it = match.begin(); it != match.end(); it++) {
        string name = it->first;
        string id = it->second;
        if (id.length() == 0) {
            id = "???";
        }
        printf("%s:%s\n", name.c_str(), id.c_str());
    }
    return 0;
}
