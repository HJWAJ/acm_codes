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
using namespace std;
int n;
int a[4];
string str[4];
int k;
string s[25];
int m;
int maxinv=0,ansp=-1;
bool issub()
{
    int i=0,j=0;
    for(;;)
    {
        if(s[j]==str[a[i]])i++;
        if(i==n)return 1;
        j++;
        if(j==k)return 0;
    }
}
int getinv()
{
    int aa[4],cnt=0,i,j;
    for(i=0;i<n;i++)aa[i]=a[i];
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(aa[j]>aa[j+1])
            {
                swap(aa[j],aa[j+1]);
                cnt++;
            }
    return cnt;
}
int main()
{
    int i,j,t=1,tt,inv;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>str[i];
        a[i]=i;
        t*=(i+1);
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>k;
        for(j=0;j<k;j++)cin>>s[j];
        tt=t;
        while(tt--)
        {
            if(issub())
            {
                inv=getinv();
                if(n*(n-1)/2-inv+1>maxinv)
                {
                    maxinv=n*(n-1)/2-inv+1;
                    ansp=i;
                }
            }
            next_permutation(a,a+n);
        }
    }
    if(ansp==-1)puts("Brand new problem!");
    else
    {
        printf("%d\n",ansp+1);
        printf("[:");
        for(i=0;i<maxinv;i++)printf("|");
        puts(":]");
    }
    return 0;
}
