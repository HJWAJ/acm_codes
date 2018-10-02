#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int n,m;
int g[105][105],d[105],t[105];
char a[105];
int ju[105];
int topsort()
{
    int i,j,flag2=1,p,temp,k=0;
    for(i=0;i<n;i++)t[i]=d[i];
    for(i=0;i<n;i++)
    {
        p=0;
        for(j=0;j<n;j++)
            if(!t[j])
            {
                p++;
                temp=j;
            }
        if(p==0&&p!=n)return 0;
        if(p>1)flag2=-1;
        ju[k++]=temp;
        t[temp]=-1;
        for(j=0;j<n;j++)
            if(g[temp][j])
                t[j]--;
    }
    return flag2;
}
int main()
{
    int i,j,q,flag;
    while(scanf("%d%d",&n,&m) && (n||m))
    {
        flag=0;
        memset(g,0,sizeof(g));
        memset(d,0,sizeof(d));
        for(i=0;i<m;i++)
        {
            scanf("%s",a);
            g[a[0]-'A'][a[2]-'A']=1;
            d[a[2]-'A']++;
            if(flag==0)q=topsort();
            if(q==1 && flag==0)
            {
                printf("Sorted sequence determined after %d relations: ",i+1);
                for(j=0;j<n;j++)printf("%c",ju[j]+'A');
                printf(".\n");
                flag=1;
            }
            if(q==0 && flag==0)
            {
                printf("Inconsistency found after %d relations.\n",i+1);
                flag=1;
            }
        }
        if(flag==0)printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
