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
char s[1005];
int n;
char ans[55][1005];
void rev(char s[])
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
        swap(s[i], s[len - 1 - i]);
}
bool isPalindromic(int len)
{
    for (int i = 0; i < len / 2; i++)
        if (s[i] != s[len - 1 - i])
            return false;
    return true;
}
void decrease(int len)
{
    // 123xx -> 123; 12xx -> 12
    for (int i = len - 1; i >= len / 2; i--)
        ans[n][i] = s[i];

    // 123xx -> 122; 12xx -> 11
    int pos = len / 2;
    ans[n][pos]--;
    while (ans[n][pos] < '0')
    {
        ans[n][pos] += 10;
        ans[n][pos + 1]--;
        pos++;
    }

    // 123xx -> 12221; 12xx -> 1111
    for (int i = 0; i < (len + 1) / 2; i++)
        ans[n][i] = ans[n][len - 1 - i];

    // 1000 -> 09 -> 999; 10000 -> 09990 -> 9999
    if (ans[n][len - 1] == '0')
    {
        ans[n][len - 1] = '\0';
        ans[n][0] = '9';
    }

    // s -= palindrome
    for (int i = 0; i < len; i++)
    {
        if (ans[n][i] == '\0') break;
        s[i] -= ans[n][i] - '0';
        if (s[i] < '0')
        {
            s[i] += 10;
            s[i + 1]--;
        }
    }

    // s leading zeros
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '0') s[i] = '\0';
        else break;
    }

    n++;
}
int main()
{
    int t, tt = 0, len;
    scanf("%d", &t);
    while (t--)
    {
        tt++;
        printf("Case #%d:\n", tt);
        scanf("%s", s);
        rev(s);
        n = 0;
        memset(ans, 0, sizeof(ans));
        while (1)
        {
            len = strlen(s);
            if (len == 1 || isPalindromic(len))
            {
                strcpy(ans[n], s);
                n++;
                break;
            }
            else if (len == 2)
            {
                if (s[1] == '1')
                {
                    ans[n][0] = '9';
                    n++;
                    s[0] -= 9;
                    if (s[0] < '0')
                    {
                        s[0] += 10;
                        s[1] = '\0';
                    }
                }
                else if (s[0] > s[1])
                {
                    ans[n][0] = ans[n][1] = s[1];
                    n++;
                    s[0] -= s[1] - '0';
                    s[1] = '\0';
                }
                else
                {
                    decrease(len);
                }
            }
            else decrease(len);
        }

        printf("%d\n", n);
        for (int i = 0; i < n; i++)
        {
            rev(ans[i]);
            puts(ans[i]);
        }
    }
    return 0;
}
