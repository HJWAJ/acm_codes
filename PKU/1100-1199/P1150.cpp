#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int num[100],n,m,form[4][4]={6,2,4,8,1,3,9,7,1,7,9,3,1,9,1,9};

int cnt25(int n,int val)
{
    int ans=0,vval=val;
    while(n/val)
    {
        ans+=(n/val);
        val*=vval;        
    }    
    return ans;
}

int cntend(int n,int val)
{
    int ans=0,i,j;
    for(i=n;i>0;i/=2)
        for(j=i;j>0;j/=5)
        {
            ans+=j/10;
            if(j%10>=val)ans++;
        }
    return ans;    
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=1;
        m=n-m;
        num[2]=cnt25(n,2)-cnt25(m,2);
        num[5]=cnt25(n,5)-cnt25(m,5);
        if(num[5]>num[2])
        {
            printf("5\n");
            continue;                 
        }            
        else if(num[2]==num[5])ans=1;
        else ans=form[0][(num[2]-num[5])%4];    
        num[3]=cntend(n,3)-cntend(m,3);
        ans=ans*form[1][num[3]%4]%10;
        num[7]=cntend(n,7)-cntend(m,7);
        ans=ans*form[2][num[7]%4]%10;
        num[9]=cntend(n,9)-cntend(m,9);
        ans=ans*form[3][num[9]%2]%10;
        printf("%d\n",ans);                   
    }
     
    //system("pause");    
    return 0;
}
