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
bool a[10],b[10];
int aa[10],bb[10],num=0;
bool ok()
{
    /*
    for(int i=0;i<10;i++)
        if(a[i])
            cout<<i<<' ';
    cout<<endl;
    for(int i=0;i<10;i++)
        if(b[i])
            cout<<i<<' ';
    cout<<endl<<endl;
    //getchar();
    */
    int s[]={0,0,0,1,2,3,4,6,8};
    int t[]={1,4,9,6,5,6,9,4,1};
    for(int i=0;i<9;i++)
        if(!(a[s[i]] && b[t[i]]) && !(a[t[i]] && b[s[i]]))
            return 0;
    //cout<<"!!!"<<endl;
    return 1;
}
void dfs2(int n,int r,int res[],int cnt)
{
    if(cnt==r)
    {
        for(int i=0;i<r;i++)
        {
            //cout<<res[i]<<' ';
            b[res[i]]=1;
            if(res[i]==9 || res[i]==6)b[6]=b[9]=1;
        }
        if(ok())num++;
        //cout<<endl;
        memset(b,0,sizeof(b));
        return;
    }
    if(n==0)return;
    res[cnt]=n-1;
    dfs2(n-1,r,res,cnt+1);
    dfs2(n-1,r,res,cnt);
}
void dfs1(int n,int r,int res[],int cnt)
{
    if(cnt==r)
    {
        for(int i=0;i<r;i++)
        {
            //cout<<res[i]<<' ';
            a[res[i]]=1;
            if(res[i]==9 || res[i]==6)a[6]=a[9]=1;
        }
        //cout<<endl;
        dfs2(10,6,bb,0);
        memset(a,0,sizeof(a));
        return;
    }
    if(n==0)return;
    res[cnt]=n-1;
    dfs1(n-1,r,res,cnt+1);
    dfs1(n-1,r,res,cnt);
}
int main()
{
    //freopen("1.txt","w",stdout);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    dfs1(10,6,aa,0);
    printf("%d\n",num/2);
    return 0;
}
