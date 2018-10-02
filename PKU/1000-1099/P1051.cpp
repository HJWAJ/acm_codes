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
using namespace std;
char m1[26][10] =
{
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."
};
char m2[4][10] =
{
    "..--", // _
    ".-.-", // ,
    "---.", // .
    "----"  // ?
};
char s[105];
char con[505];
int main()
{
    int t, tt = 0, len;
    scanf("%d", &t);
    while (t--)
    {
        tt++;
        scanf("%s", s);
        printf("%d: ", tt);
        len = strlen(s);
        con[0] = '\0';
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '_') strcat(con, m2[0]);
            else if (s[i] == ',') strcat(con, m2[1]);
            else if (s[i] == '.') strcat(con, m2[2]);
            else if (s[i] == '?') strcat(con, m2[3]);
            else strcat(con, m1[s[i] - 'A']);
        }
        int p = 0, tmplen;
        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == '_') tmplen = strlen(m2[0]);
            else if (s[i] == ',') tmplen = strlen(m2[1]);
            else if (s[i] == '.') tmplen = strlen(m2[2]);
            else if (s[i] == '?') tmplen = strlen(m2[3]);
            else tmplen = strlen(m1[s[i] - 'A']);
            if (strlen(m2[0]) == tmplen && !strncmp(con + p, m2[0], tmplen)) printf("_");
            else if (strlen(m2[1]) == tmplen && !strncmp(con + p, m2[1], tmplen)) printf(",");
            else if (strlen(m2[2]) == tmplen && !strncmp(con + p, m2[2], tmplen)) printf(".");
            else if (strlen(m2[3]) == tmplen && !strncmp(con + p, m2[3], tmplen)) printf("?");
            else
            {
                for (int j = 0; j < 26; j++)
                    if (strlen(m1[j]) == tmplen && !strncmp(con + p, m1[j], tmplen))
                    {
                        printf("%c", char('A' + j));
                        break;
                    }
            }
            p += tmplen;
        }
        puts("");
    }
    return 0;
}
