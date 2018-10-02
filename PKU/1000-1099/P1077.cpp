#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int order(const char *s, int n)
{
    int i, j, temp, num;

    num = 0;

    for (i = 0; i < n-1; i++)
    {
        temp = 0;
        for (j = i + 1; j < n; j++)
        {
            if (s[j] < s[i])
                temp++;
        }
        num += fac[s[i] -1] * temp;
    }
    return num;
}

bool is_equal(const char *b1, const char *b2)
{
    for(int i=0; i<9; i++)
        if(b1[i] != b2[i])
            return false;
    return true;
}


//hash
struct node
{
    char board[9];
    char space;//空格所在位置
};

const int TABLE_SIZE = 362880;

int hash(const char *cur)
{
    return order(cur, 9);
}

/* 整数映射成排列 */
void get_node(int num, node &tmp)
{
    int n=9;
    int a[9]; //求逆序数
    for (int i = 2; i <= n; ++i)
    {
        a[i - 1] = num % i;
        num = num / i;
        tmp.board[i - 1] = 0;//初始化
    }
    tmp.board[0] = 0;
    int rn, i;
    for (int k = n; k >= 2; k--)
    {
        rn = 0;
        for (i = n - 1; i >= 0; --i)
        {
            if (tmp.board[i] != 0)
                continue;
            if (rn == a[k - 1])
                break;
            ++rn;
        }
        tmp.board[i] = k;
    }
    for (i = 0; i < n; ++i)
        if (tmp.board[i] == 0)
        {
            tmp.board[i] = 1;
            break;
        }
    tmp.space = n - a[n-1] -1;
}

//启发函数: 除去x之外到目标的网格距离和
int goal_state[9][2] = {{0,0}, {0,1}, {0,2},
    {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}
};
int h(const char *board)
{
    int k;
    int hv = 0;
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
        {
            k = i*3+j;
            if(board[k] != 9)
            {
                hv += abs(i - goal_state[board[k]-1][0]) +
                      abs(j - goal_state[board[k] -1][1]);
            }
        }
    return hv;
}

int f[TABLE_SIZE], d[TABLE_SIZE];//估计函数和深度

//优先队列的比较对象
struct cmp
{
    bool operator () (int u, int v)
    {
        return f[u] > f[v];
    }
};
char color[TABLE_SIZE];//0, 未访问；1, 在队列中，2, closed
int parent[TABLE_SIZE];
char move[TABLE_SIZE];
int step[4][2] = {{-1, 0},{1, 0}, {0, -1}, {0, 1}};//u, d, l, r

void A_star(const node & start)
{
    int x, y, k, a, b;
    int u, v;
    priority_queue<int, vector<int>, cmp> open;
    memset(color, 0, sizeof(char) * TABLE_SIZE);

    u = hash(start.board);
    parent[u] = -1;
    d[u] = 0;
    f[u] = h(start.board);
    open.push(u);
    color[u] = 1;

    node tmp, cur;
    while(!open.empty())
    {
        u = open.top();
        if(u == 0)
            return;
        open.pop();

        get_node(u, cur);

        k = cur.space;
        x = k / 3;
        y = k % 3;
        for(int i=0; i<4; ++i)
        {
            a = x + step[i][0];
            b = y + step[i][1];
            if(0<=a && a<=2 && 0<=b && b<=2)
            {
                tmp = cur;
                tmp.space = a*3 + b;
                swap(tmp.board[k], tmp.board[tmp.space]);
                v = hash(tmp.board);
                if(color[v] == 1 && (d[u] + 1) < d[v]) //v in open
                {
                    move[v] = i;
                    f[v] = f[v] - d[v] + d[u] + 1;//h[v]已经求过
                    d[v] = d[u] + 1;
                    parent[v] = u;
                    //直接插入新值, 有冗余
                    open.push(v);
                }
                else if(color[v] == 2 && (d[u]+1)<d[v]) //v in closed
                {
                    move[v] = i;
                    f[v] = f[v] - d[v] + d[u] + 1;//h[v]已经求过
                    d[v] = d[u] + 1;
                    parent[v] = u;
                    open.push(v);
                    color[v] = 1;
                }
                else if(color[v] == 0)
                {
                    move[v] = i;
                    d[v] = d[u] + 1;
                    f[v] = d[v] + h(tmp.board);
                    parent[v] = u;
                    open.push(v);
                    color[v] = 1;
                }
            }
        }
        color[u] = 2; //
    }
}

void print_path()
{
    int n, u;
    char path[1000];
    n = 1;
    path[0] = move[0];
    u = parent[0];
    while(parent[u] != -1)
    {
        path[n] = move[u];
        ++n;
        u = parent[u];
    }
    for(int i=n-1; i>=0; --i)
    {
        if(path[i] == 0)
            printf("u");
        else if(path[i] == 1)
            printf("d");
        else if(path[i] == 2)
            printf("l");
        else
            printf("r");
    }
}

int main()
{
    node start;
    char c;
    for(int i=0; i<9; ++i)
    {
        cin >> c;
        if(c == 'x')
        {
            start.board[i] = 9;
            start.space = i;
        }
        else start.board[i] = c - '0';
    }
    A_star(start);

    if(color[0] != 0)
    {
        print_path();
        puts("");
    }
    else puts("unsolvable");
    return 0;
}
