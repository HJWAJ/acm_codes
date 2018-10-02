#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int y,m,d,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&y,&m,&d);
        if(m==9 && d==30)puts("YES");
        else if(m==11 && d==30)puts("YES");
        else if((m&1) && (d&1))puts("YES");
        else if((!(m&1)) && (!(d&1)))puts("YES");
        else puts("NO");
    }
    return 0;
}
