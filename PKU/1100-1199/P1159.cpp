#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

short int dp[5005][5005];

int min(int a,int b)
{
    return a<b?a:b;    
}

int main()
{
    int len,i,j;
    char s[5005];
    while(scanf("%d",&len)!=EOF)
    {
         scanf("%s",s);
         memset(dp,0,sizeof(dp));
         for(i=len-1;i>=0;i--)
             for(j=i;j<len;j++)
             {
                 if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
                 else dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
             }            
         printf("%d\n",dp[0][len-1]);
    }    
    
    return 0;
}
