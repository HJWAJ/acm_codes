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
#include<ctime>
using namespace std;
map<int,int> a,b;
int f[100005];
int main()
{
    int n,tmp,i;
    scanf("%d",&n);
    a.clear();
    b.clear();
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        a.insert(make_pair(tmp,i));
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        b.insert(make_pair(tmp,i));
    }
    for(i=0;i<n;i++)f[b[i+1]]=a[i+1];
    for(i=0;i<n-1;i++)printf("%d ",f[i]+1);
    printf("%d\n",f[n-1]+1);
    return 0;
}
