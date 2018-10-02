#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
char pattern[105];
char match[105];
char match1[105];
void gao(char s[])
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        if (s[i] >= 'a')
            s[i] = s[i] - 'a' + 'A';
}
int main()
{
    int n, b;
    while (scanf("%s", pattern) != EOF)
    {
        scanf("%d%d", &b, &n);
        if (b == 0) gao(pattern);
        while (n--)
        {
            scanf("%s", match);
            strcpy(match1, match);
            if (b == 0) gao(match);
            if (strstr(match, pattern)) puts(match1);
        }
    }
    return 0;
}
