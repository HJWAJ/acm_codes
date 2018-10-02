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
const char b64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char s[2][100005];
void encode(char src[], char dest[])
{
    int slen = strlen(src);
    int dlen = 0;

    unsigned char byte = 0;
    int remain = 0;

    for (int i = 0; i < slen; i++)
    {
        unsigned char ch = (unsigned char) src[i];
        if (remain == 0)
        {
            dest[dlen++] = b64[(ch & 0xFC) >> 2];
            byte = (ch & 0x03);
            remain = 2;
        }
        else if (remain == 2)
        {
            dest[dlen++] = b64[(byte << 4) + ((ch & 0xF0) >> 4)];
            byte = (ch & 0x0F);
            remain = 4;
        }
        else if (remain == 4)
        {
            dest[dlen++] = b64[(byte << 2) + ((ch & 0xC0) >> 6)];
            dest[dlen++] = b64[ch & 0x3F];
            byte = 0;
            remain = 0;
        }
    }

    if (remain == 2)
    {
        dest[dlen++] = b64[byte << 4];
        dest[dlen++] = '=';
        dest[dlen++] = '=';
    }
    else if (remain == 4)
    {
        dest[dlen++] = b64[byte << 2];
        dest[dlen++] = '=';
    }

    dest[dlen] = '\0';
}
int main()
{
    int t, tt = 0, n, x = 0;
    scanf("%d", &t);
    while (t--)
    {
        tt++;
        printf("Case #%d: ", tt);
        scanf("%d%s", &n, s[x]);
        while (n--)
        {
            encode(s[x], s[x ^ 1]);
            x ^= 1;
        }
        printf("%s\n", s[x]);
    }
    return 0;
}
