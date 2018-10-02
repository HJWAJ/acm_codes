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
#include<list>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
char mapp[]={"6789TJQKA"};
bool big(char a,char b)
{
    int pos1,pos2,i;
    for(i=0;i<10;i++)
        if(mapp[i]==a)
        {
            pos1=i;
            break;
        }
    for(i=0;i<10;i++)
        if(mapp[i]==b)
        {
            pos2=i;
            break;
        }
    if(pos1>pos2)return 1;
    return 0;
}
int main()
{
    char ch[2],s1[5],s2[5];
    scanf("%s%s%s",ch,s1,s2);
    if(s1[1]==s2[1])
    {
        if(big(s1[0],s2[0]))puts("YES");
        else puts("NO");
    }
    else if(s1[1]==ch[0])puts("YES");
    else if(s2[1]==ch[0])puts("NO");
    else
    {
        if(big(s1[0],s2[0]))puts("YES");
        else puts("NO");
    }
    return 0;
}
