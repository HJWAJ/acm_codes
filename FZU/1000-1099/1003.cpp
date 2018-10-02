#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;
int main()
{
    int t,a[12];
    int i,j,len,max,num;
    char s[3][50];
    bool judge[12];
    cin>>t;
    while(t--)
    {
        max=0;
        memset(a,0,sizeof(a));
        memset(judge,0,sizeof(judge));
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)cin>>s[j];
            len=strlen(s[0]);
            if(s[2][0]=='u')
            {
                for(j=0;j<len;j++)if(judge[s[0][j]-'A']==0)a[s[0][j]-'A']++;
                for(j=0;j<len;j++)if(judge[s[1][j]-'A']==0)a[s[1][j]-'A']--;
            }
            if(s[2][0]=='d')
            {
                for(j=0;j<len;j++)if(judge[s[0][j]-'A']==0)a[s[0][j]-'A']--;
                for(j=0;j<len;j++)if(judge[s[1][j]-'A']==0)a[s[1][j]-'A']++;
            }
            if(s[2][0]=='e')
            {
                for(j=0;j<len;j++)judge[s[0][j]-'A']=1;
                for(j=0;j<len;j++)judge[s[1][j]-'A']=1;
            }
        }
        for(i=0;i<12;i++)if(max<abs(a[i]) && judge[i]==0){max=abs(a[i]);num=i;}
        if(a[num]<0)cout<<char(num+'A')<<" is the counterfeit coin and it is "<<"light."<<endl;
        else cout<<char(num+'A')<<" is the counterfeit coin and it is "<<"heavy."<<endl;
    }
    return 0;
}
