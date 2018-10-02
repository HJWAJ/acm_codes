#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,len,i,flag,cnt=0;
    bool val[26];
    memset(val,0,sizeof(val));
    char s[1000];
    scanf("%d%s",&n,s);
    len=strlen(s);
    for(i=0;i<=(len-1)/2;i++)
    {
        if(s[i]!=s[len-1-i])
        {
            if(s[i]=='?')
            {
                s[i]=s[len-1-i];
                val[s[i]-'a']=1;
            }
            else if(s[len-1-i]=='?')
            {
                s[len-1-i]=s[i];
                val[s[i]-'a']=1; 
            }
            else 
            {
                printf("IMPOSSIBLE\n");
                return 0;     
            }
        }
        else
        {
            if(s[i]!='?')val[s[i]-'a']=1;
            else continue;    
        }
    }
    //printf("%s\n",s);
    for(i=0;i<n;i++)
        if(val[i]==0)cnt++;
    //printf("%d\n",cnt);
    if(cnt==0)
    {
        for(i=0;i<=(len-1)/2;i++)
            if(s[i]=='?')s[i]=s[len-1-i]='a';
        printf("%s\n",s);
        return 0;          
    }
    for(i=(len-1)/2;i>=0;i--)
    {
        if(s[i]=='?')cnt--;
        if(cnt==0)break;
    }
    if(i<0)
    {
        printf("IMPOSSIBLE\n");
        return 0;   
    }
    i--;
    //printf("%d",i);
    for(;i>=0;i--)
        if(s[i]=='?')s[i]=s[len-1-i]='a';
    //printf("%s\n",s);
    flag=0;
    for(i=0;i<=(len-1)/2;i++)
    {
        if(s[i]=='?')
        {
            while(val[flag]!=0)flag++;
            s[i]=s[len-1-i]=char(flag+'a');
            flag++;         
        }                     
    }
    printf("%s\n",s);    
    
    //system("pause");
    return 0;
}
