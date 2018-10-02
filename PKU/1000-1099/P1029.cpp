#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int m,n,group[100],a[100][1000];
    bool judge[1001];
    int f[1001];
    memset(f,0,sizeof(f));
    char weigh[100];
    int i,j,num,max=0;
    cin>>m>>n;
    for(i=1;i<=m;i++)judge[i]=0;
    for(i=0;i<n;i++)
    {
        cin>>group[i];
        for(j=0;j<group[i]*2;j++)cin>>a[i][j];
        cin>>weigh[i];                
    }
    
    for(i=0;i<n;i++)
    {
        if(weigh[i]=='=')
        {
            for(j=0;j<group[i]*2;j++)judge[a[i][j]]=1;                 
        }                
    }   
    
    for(i=0;i<n;i++)
    {
        if(weigh[i]=='>')
        {
            for(j=0;j<group[i];j++)
            {
                swap(a[i][j],a[i][j+group[i]]);
            }                 
        }                
    }  
    
    for(i=0;i<n;i++)
    {
        if(weigh[i]!='=')
        {
            for(j=0;j<group[i];j++)
            {
                f[a[i][j]]--;                       
            }
            for(;j<2*group[i];j++)
            {
                f[a[i][j]]++;                      
            }
        }               
    }
    
    for(i=1;i<=m;i++)if(max<abs(f[i]))max=abs(f[i]);
    for(i=1;i<=m;i++)
    {
        if(max!=abs(f[i]))judge[i]=1;
    }
    
    for(i=1;i<=m;i++)if(judge[i]==0){num=i;break;}
    for(i=num+1;i<=m;i++)if(judge[i]==0){cout<<0<<endl;break;}
    if(i==m+1)cout<<num<<endl;
    
    system("pause");
    return 0;
}
