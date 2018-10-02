/*
ID: hjw00002
PROG: barn1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    int m,s,c,i,stall[205],dis[205],ans=0;
    scanf("%d%d%d",&m,&s,&c);
    if(m>=c){printf("%d\n",c);return 0;}
    for(i=0;i<c;i++)scanf("%d",stall+i);
    sort(stall,stall+c);
    ans=stall[c-1]-stall[0];
    for(i=0;i<c-1;i++)dis[i]=stall[i+1]-stall[i];
    sort(dis,dis+c-1);
    for(i=0;i<m-1;i++)ans-=dis[c-2-i];
    printf("%d\n",ans+m);
    
    //system("pause");
    return 0;
}
