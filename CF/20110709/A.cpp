#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int main()
{
    char s[105];
    scanf("%s",s);
    int len=strlen(s),i;
    for(i=0;i<=len-7;i++)
    {
        if(s[i]=='0')
            if(s[i+1]=='0' && s[i+2]=='0' && s[i+3]=='0' && s[i+4]=='0' && s[i+5]=='0' && s[i+6]=='0')
            {
                puts("YES");
                break;
            }
        if(s[i]=='1')
            if(s[i+1]=='1' && s[i+2]=='1' && s[i+3]=='1' && s[i+4]=='1' && s[i+5]=='1' && s[i+6]=='1')
            {
                puts("YES");
                break;
            }
    }
    if(i>len-7)puts("NO");
    return 0;
}
