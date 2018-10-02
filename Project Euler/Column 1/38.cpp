#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
priority_queue<int> q;
bool ok(int aa[],int len)
{
    bool bo[10];
    int a[10];
    memcpy(a,aa,10);
    memset(bo,0,sizeof(bo));
    int i;
    for(i=0;i<len;i++)
    {
        while(a[i])
        {
            if(a[i]%10==0)return 0;
            if(bo[a[i]%10])return 0;
            bo[a[i]%10]=1;
            a[i]/=10;
        }
    }
    return 1;
}
int main()
{
    int i,j,a[10];
    while(!q.empty())q.pop();
    q.push(918273645);
    for(i=25;i<34;i++)
    {
        for(j=1;j<5;j++)
            a[j-1]=i*j;
        if(ok(a,4))q.push(a[0]*10000000+a[1]*100000+a[2]*1000+a[3]);
    }
    for(i=100;i<334;i++)
    {
        for(j=1;j<4;j++)
            a[j-1]=i*j;
        if(ok(a,3))q.push(a[0]*1000000+a[1]*1000+a[2]);
    }
    for(i=5000;i<10000;i++)
    {
        for(j=1;j<3;j++)
            a[j-1]=i*j;
        if(ok(a,2))q.push(a[0]*100000+a[1]);
    }
    printf("%d\n",q.top());
    return 0;
}
