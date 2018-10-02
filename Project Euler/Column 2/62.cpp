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
#include<windows.h>
using namespace std;
struct node1
{
    int a[10];
    bool operator <(const node1 b)const
    {
        int i;
        for(i=0;i<10;i++)
            if(a[i]<b.a[i])
                return 1;
        return 0;
    }
    bool operator ==(const node1 b)const
    {
        int i;
        for(i=0;i<10;i++)
            if(this->a[i]!=b.a[i])
                return 0;
        return 1;
    }
};
struct node2
{
    long long a[10];
    int cnt;
};
struct linear
{
    node1 n1;
    node2 n2;
}l[10005];
int num=0;
node1 getnum(long long n)
{
    long long nn=n;
    node1 a;
    int i;
    for(i=0;i<10;i++)a.a[i]=0;
    while(n)
    {
        a.a[n%10]++;
        n/=10;
    }
    return a;
}
int main()
{
    long long i,tmp,mmin=9999999,j,k;
    node1 mynode,amynode;
    node2 nodes;
    amynode.a[0]=1;
    amynode.a[1]=1;
    amynode.a[2]=1;
    amynode.a[3]=2;
    amynode.a[4]=1;
    amynode.a[5]=2;
    amynode.a[6]=1;
    amynode.a[7]=1;
    amynode.a[8]=1;
    amynode.a[9]=1;
    for(i=1;i<10000;i++)
    {
        tmp=i*i*i;
        mynode=getnum(tmp);
        //if(mynode==amynode)cout<<i<<endl;
        for(j=0;j<num;j++)
            if(l[j].n1==mynode)
            {
                l[j].n2.cnt++;
                l[j].n2.a[l[j].n2.cnt-1]=i;
                if(l[j].n2.cnt==5)
                {
                    for(k=0;k<5;k++)
                    {
                        //printf("%lld ",l[j].n2.a[k]);
                        if(l[j].n2.a[k]<mmin)mmin=l[j].n2.a[k];
                    }
                    printf("%lld\n",mmin*mmin*mmin);
                    exit(0);
                }
            }
        if(j==num)
        {
            l[num].n1=mynode;
            l[num].n2.cnt=1;
            l[num].n2.a[0]=i;
            num++;
        }
    }
    return 0;
}
