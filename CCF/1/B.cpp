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
char s[105];
int main()
{
    int tmp;
    char ch;
    while (scanf("%s", s) != EOF)
    {
        tmp = (s[0] - '0') + (s[2] - '0') * 2 + (s[3] - '0') * 3 + (s[4] - '0') * 4 + (s[6] - '0') * 5
                + (s[7] - '0') * 6 + (s[8] - '0') * 7 + (s[9] - '0') * 8 + (s[10] - '0') * 9;
        tmp %= 11;
        if (tmp == 10) ch = 'X';
        else ch = tmp + '0';
        if (s[12] == ch) puts("Right");
        else
        {
            s[12] = ch;
            puts(s);
        }
    }
    return 0;
}
