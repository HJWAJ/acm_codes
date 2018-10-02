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
char s[105];
char ans[105];
int main()
{
    int t, r, c, i, len, x, y, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", s);
        r = c = -1;
        len = strlen(s);
        if (s[0] == 'R')
        {
            for (i = 1; i < len; i++)
                if (s[i] == 'C')
                    break;
            if (s[1] >= '0' && s[1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && i < len)
            {
                r = 0;
                c = i;
            }
        }
        x = y = 0;
        if (r == -1)
        {
            i = 0;
            while (s[i] > '9')
            {
                x *= 26;
                x += s[i] - 'A' + 1;
                i++;
            }
            while (i < len)
            {
                y *= 10;
                y += s[i] - '0';
                i++;
            }
            printf("R%dC%d\n", y, x);
        }
        else
        {
            i = 1;
            while (i < c)
            {
                x *= 10;
                x += s[i] - '0';
                i++;
            }
            i = c + 1;
            while (i < len)
            {
                y *= 10;
                y += s[i] - '0';
                i++;
            }
            memset(ans, 0, sizeof(ans));
            i = 0;
            while (y)
            {
                ans[i] = y % 26;
                if (ans[i] == 0)
                {
                    ans[i] = 'Z';
                    y /= 26;
                    y--;
                }
                else
                {
                    y /= 26;
                    ans[i] += 'A' - 1;
                }
                i++;
            }
            for (j = 0; j < i / 2; j++) swap(ans[j], ans[i - 1 - j]);
            printf("%s%d\n", ans, x);
        }
    }
    // wtf
    return 0;
}
