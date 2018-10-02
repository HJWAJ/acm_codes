/*
ID: hjw00002
PROG: runround
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

bool isrev(unsigned int n)
{
    if(n<10)return 1;
    int len=0,nn=n,num,a[100],cnt[100],i,j,tmp;
    while(nn)
    {
        len++;
        nn/=10;         
    }
    nn=n;
    for(i=0;i<len;i++)
    {
        a[len-1-i]=nn%10;
        nn/=10;
    }
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<len;i++)
    {
        cnt[a[i]]++;
        if(cnt[a[i]]>1)return 0;              
    }
    memset(cnt,0,sizeof(cnt));
    j=0;
    for(i=1;i<=len;i++)
    {
        tmp=a[j];
        j=(a[j]+j)%len;
        if(cnt[j]!=0 || a[j]==tmp)return 0;
        cnt[j]=1;
    }
    if(j==0)return 1;
    return 0;
}

int main()
{    
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    unsigned int n;
    scanf("%d",&n);
    while(1)
    {
        n++;
        if(isrev(n))break;
    }
    printf("%d\n",n);
    
    //system("pause");
    return 0;
}
