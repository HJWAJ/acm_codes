/*
ID: hjw00002
PROG: hamming
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

bool islen(int a,int b,int l,int d)
{
    bool aa[10],bb[10];
    memset(aa,0,sizeof(aa));
    memset(bb,0,sizeof(bb));
    int i,cnt=0;
    for(i=l-1;i>=0;i--)aa[i]=((a>>i)&1);
    //for(i=l-1;i>=0;i--)cout<<aa[i];
    //cout<<endl;
    for(i=l-1;i>=0;i--)bb[i]=((b>>i)&1);
    //for(i=l-1;i>=0;i--)cout<<bb[i];
    //cout<<endl;
    for(i=l-1;i>=0;i--)if(aa[i]!=bb[i])cnt++;
    if(cnt>=d)return 0;
    return 1;    
}

int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    int n,b,d,a[1000],flag=1,i,j;
    int val[]={1,2,4,8,16,32,64,128,256,512,1024};
    scanf("%d%d%d",&n,&b,&d);
    a[0]=0;
    for(i=1;i<val[b+1];i++)
    {
        for(j=0;j<flag;j++)
            if(islen(i,a[j],b,d))break;
        if(j==flag)a[flag++]=i;
        if(flag==n)break;       
    }
    printf("%d",a[0]);
    for(i=1;i<n;i++)
    {
        if(i%10==0)printf("\n%d",a[i]);
        else printf(" %d",a[i]);                
    }
    printf("\n");
    
    //system("pause");
    return 0;
}
