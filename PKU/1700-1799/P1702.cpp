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
int cnt[30];
int a[30],flag,ansl[30],flagl,ansr[30],flagr;
int main()
{
    int t,n,i;
    cnt[0]=1;
    for(i=1;i<30;i++)cnt[i]=cnt[i-1]*3;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        flag=flagl=flagr=0;
        while(n)
        {
            a[flag]=n%3;
            n/=3;
            flag++;
        }
        for(i=0;i<flag;i++)
        {
            if(a[i]==2)
            {
                a[i]=-1;
                a[i+1]++;
            }
            if(a[i]==3)
            {
                a[i]=0;
                a[i+1]++;
            }
        }
        if(a[flag])flag++;
        for(i=0;i<flag;i++)
        {
            if(a[i]==1)
            {
                ansr[flagr]=i;
                flagr++;
            }
            if(a[i]==-1)
            {
                ansl[flagl]=i;
                flagl++;
            }
        }
        if(flagl==0)printf("empty");
        else
        {
            printf("%d",cnt[ansl[0]]);
            for(i=1;i<flagl;i++)printf(",%d",cnt[ansl[i]]);
        }
        printf(" ");
        if(flagr==0)printf("empty");
        else
        {
            printf("%d",cnt[ansr[0]]);
            for(i=1;i<flagr;i++)printf(",%d",cnt[ansr[i]]);
        }
        puts("");
    }
    return 0;
}
