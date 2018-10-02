#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
int lenc,lena,lenb,a[1005],c[1005],b[1005];
int gettri(int n,int a[])
{
    int len=0;
    while(n)
    {
        a[len]=n%3;
        n/=3;
        len++;
    }
    return len;
}
int main()
{
    int anum,cnum,bnum,i;
    scanf("%d%d",&anum,&cnum);
    lena=gettri(anum,a);
    lenc=gettri(cnum,c);
    if(lena>lenc)
    {
        for(i=lenc;i<lena;i++)c[i]=0;
        lenc=lena;
    }
    else
    {
        for(i=lena;i<lenc;i++)a[i]=0;
        lena=lenc;
    }
    for(i=0;i<lena;i++)
    {
        b[i]=c[i]-a[i];
        if(b[i]<0)b[i]+=3;
    }
    bnum=0;
    for(i=lena-1;i>=0;i--)
    {
        bnum*=3;
        bnum+=b[i];
    }
    printf("%d\n",bnum);
    return 0;
}
