#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
#include<sstream>
using namespace std;
int a[105];
void gao(int i,int j)
{
    for(int k=i;k<=j;k++)a[k]^=1;
}
int calc(int n)
{
    int cnt=0;
    for(int i=0;i<n;i++)
        if(a[i])
            cnt++;
    return cnt;
}
void re(int i,int j)
{
    gao(i,j);
}
void print(int n)
{
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
    cout<<endl;
}
int main()
{
    int n,i,j,m=0,tmp;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        {
            gao(i,j);
            //print(n);
            tmp=calc(n);
            if(tmp>m)m=tmp;
            re(i,j);
        }
    printf("%d\n",m);
    return 0;
}
