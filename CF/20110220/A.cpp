#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int m,n,i,j,num,len,cnt,flag;
    bool val[1005];
    char s[100];
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(val,0,sizeof(val));
        flag=cnt=0;
        getchar();
        for(i=0;i<n;i++)
        {
            gets(s);
            len=strlen(s);
            num=0;
            if(s[7]=='l')
            {
                for(j=15;j<len;j++)
                {
                    num*=10;
                    num+=(s[j]-'0');                   
                }
                for(j=num;j<=m;j++)val[j]=1;     
            }
            else
            {
                for(j=16;j<len;j++)
                {
                    num*=10;
                    num+=(s[j]-'0');                   
                }
                if(num>=m){printf("-1\n");flag=1;}    
                for(j=num;j>0;j--)val[j]=1;
            }
        }
        for(j=1;j<=m;j++)
            if(val[j]==0)cnt++;
        if(flag==1)goto label;
        if(cnt)printf("%d\n",cnt);
        else printf("-1\n");
        label:;      
    }    
    
    return 0;
}
