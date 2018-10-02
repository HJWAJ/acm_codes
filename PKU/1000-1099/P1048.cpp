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
using namespace std;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // l, t, r, b
const char AND = '&';
const char OR = '|';
const char AND_NOT = '#';
const char OR_NOT = '^';

char tmp[105];
char circuit[105][105];
char value[30];
int r, c; // [1 .. r], [1 .. c]

bool upper(char c)
{
    return c >= 'A' && c <= 'Z';
}
bool lower(char c)
{
    return c >= 'a' && c <= 'z';
}

struct Tree
{
    char node_val;
    Tree* left;
    Tree* right;
};
void find_question_mark(int &x, int &y)
{
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (circuit[i][j] == '?')
            {
                x = i;
                y = j;
                return;
            }
}
void find_dest(int &x, int &y, int &d, bool need_find_dir)
{
    int i = 0;
    if (need_find_dir)
    {
        for (i = 0; i < 4; i++)
            if (circuit[x + dir[i][1]][y + dir[i][0]] == '-'
                || circuit[x + dir[i][1]][y + dir[i][0]] == '+'
                || circuit[x + dir[i][1]][y + dir[i][0]] == '|')
                break;
    }
    x += dir[i][1];
    y += dir[i][0];
    //printf("node move to: (%d, %d), dir = %d, char = %c\n", x, y, i, circuit[x][y]);
    while (circuit[x][y] == '-'
            || circuit[x][y] == '+'
            || circuit[x][y] == '|')
    {
        if (circuit[x][y] == '-'
            || circuit[x][y] == '|')
        {
            x += dir[i][1];
            y += dir[i][0];
            //printf("node move to: (%d, %d), dir = %d, char = %c\n", x, y, i, circuit[x][y]);
        }
        else
        {
            for (int j = 0; j < 4; j++)
                if (j != (i + 2) % 4
                    && ((circuit[x + dir[j][1]][y + dir[j][0]] == '-' && (j == 0 || j == 2))
                        || circuit[x + dir[j][1]][y + dir[j][0]] == '+'
                        || (circuit[x + dir[j][1]][y + dir[j][0]] == '|' && (j == 1 || j == 3))))
                {
                    i = j;
                    x += dir[i][1];
                    y += dir[i][0];
                    //printf("node move to: (%d, %d), dir = %d, char = %c\n", x, y, i, circuit[x][y]);
                    break;
                }
        }
    }
    d = i;
}
char do_negate(char c)
{
    if (c == AND) return AND_NOT;
    if (c == OR) return OR_NOT;
    if (c == AND_NOT) return AND;
    if (c == OR_NOT) return OR;
    if (upper(c)) return c - 'A' + 'a';
    return c - 'a' + 'A';
}
Tree* build_node(int x, int y, bool negate, bool need_find_dir)
{
    Tree* root = new Tree();
    root->node_val = 0;
    int d = -1;
    //printf("node from: (%d, %d), dir = %d\n", x, y, d);
    find_dest(x, y, d, need_find_dir);
    //printf("node at: (%d, %d), dir = %d\n", x, y, d);
    if (circuit[x][y] == 'o')
    {
        x += dir[d][1];
        y += dir[d][0];
        switch (circuit[x][y]) {
            case ')':
                root->node_val = AND_NOT;
                break;
            case '>':
                root->node_val = OR_NOT;
                break;
            default:
                break;
        }
    }
    else
    {
        switch (circuit[x][y]) {
            case ')':
                root->node_val = AND;
                break;
            case '>':
                root->node_val = OR;
                break;
            default:
                break;
        }
    }
    bool end = false;
    if (root->node_val == 0)
    {
        root->node_val = circuit[x][y];
        end = true;
    }
    //printf("tree root before negate: %c\n", root->node_val);
    if (negate) root->node_val = do_negate(root->node_val);
    //printf("tree root after negate: %c\n", root->node_val);
    if (end)
    {
        root->left = root->right = NULL;
    }
    else
    {
        if (circuit[x - 1][y - 3] == 'o') root->left = build_node(x - 1, y - 3, true, true);
        else root->left = build_node(x - 1, y - 2, false, true);

        if (circuit[x + 1][y - 3] == 'o') root->right = build_node(x + 1, y - 3, true, true);
        else root->right = build_node(x + 1, y - 2, false, true);
    }

    return root;
}
Tree* make_tree()
{
    int qx, qy;
    find_question_mark(qx, qy);
    return build_node(qx, qy, false, true);
}
int calc(Tree *root)
{
    char val = root->node_val;
    //printf("cur calc node: %c\n", root->node_val);
    if (upper(val)) return value[val - 'A'] - '0';
    if (lower(val)) return (value[val - 'a'] - '0') ^ 1;
    if (val == AND) return calc(root->left) & calc(root->right);
    if (val == OR) return calc(root->left) | calc(root->right);
    if (val == AND_NOT) return (calc(root->left) & calc(root->right)) ^ 1;
    // else val == OR_NOT
    return (calc(root->left) | calc(root->right)) ^ 1;
}
void print_graph()
{
    for (int i = 0; i <= r + 1; i++)
    {
        for (int j = 0; j <= c + 1; j++)
        {
            if (circuit[i][j] == 0) printf("_");
            else printf("%c", circuit[i][j]);
        }
        puts("");
    }
}
int main()
{
    memset(circuit, 0, sizeof(circuit));
    bool firstCase = true;
    while (gets(tmp))
    {
        if (!firstCase) puts("");
        r = c = 0;
        while (strcmp(tmp, "*"))
        {
            int len = (int) strlen(tmp);
            if (len > c) c = len;
            strcpy(circuit[r + 1] + 1, tmp);
            r++;
            gets(tmp);
        }
        //print_graph();
        Tree* root = make_tree();
        while (gets(value) && strcmp(value, "*")) printf("%d\n", calc(root));
        firstCase = false;
        memset(circuit, 0, sizeof(circuit));
    }
    return 0;
}
