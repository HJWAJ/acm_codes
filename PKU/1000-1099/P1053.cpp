#include <iostream>
#include <cstdio>
using namespace std;
char s[12][5];
bool ok(int i, int j, int k, int cnt)
{
    int ok = 0;
    for (int l = 0; l < 4; l++)
    {
        if (s[i][l] == s[j][l] && s[j][l] == s[k][l]) ok++;
        else if (s[i][l] != s[j][l] && s[j][l] != s[k][l] && s[i][l] != s[k][l]) ok++;
    }
    if (ok == 4)
    {
        if (cnt == 0) printf("SETS:   %d.  %s %s %s\n", cnt + 1, s[i], s[j], s[k]);
        else printf("        %d.  %s %s %s\n", cnt + 1, s[i], s[j], s[k]);
        return true;
    }
    return false;
}
int main()
{
    bool firstCase = true;
    while (scanf("%s", s[0]) != EOF)
    {
        for (int i = 1; i < 12; i++) scanf("%s", s[i]);
        if (!firstCase) puts("");
        int cnt = 0;
        printf("CARDS: ");
        for (int i = 0; i < 12; i++) printf(" %s", s[i]);
        puts("");
        for (int i = 0; i < 12; i++)
            for (int j = i + 1; j < 12; j++)
                for (int k = j + 1; k < 12; k++)
                    if (ok(i, j, k, cnt))
                        cnt++;
        if (cnt == 0) puts("SETS:   *** None Found ***");
        firstCase = false;
    }
    return 0;
}