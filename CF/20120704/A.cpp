#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
    int x,t,a,b,da,db,i,j,aa,bb;
    scanf("%d%d%d%d%d%d",&x,&t,&a,&b,&da,&db);
    if(x==0)puts("YES");
    else
    {
        for(i=0;i<t;i++)
            for(j=0;j<t;j++)
            {
                aa=a-i*da;
                bb=b-j*db;
                if(aa==x || bb==x || aa+bb==x)
                {
                    puts("YES");
                    return 0;
                }
            }
        puts("NO");
    }
    return 0;
}
