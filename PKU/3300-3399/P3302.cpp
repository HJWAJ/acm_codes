#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s1[1001],s2[1001],s[1001];
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s>>s1;
        int len=strlen(s);
        int len1=strlen(s1);
        int i,j;
        for(i=0;i<len1;i++)
            s2[len1-1-i]=s1[i];
        j=0;
        for(i=0;i<len;i++)
        {
            if(s1[j]==s[i]){s1[j]=0;j++;}
            if(j==len1)break;                
        }
        j=0;
        for(i=0;i<len;i++)
        {
            if(s2[j]==s[i]){s2[j]=0;j++;}
            if(j==len1)break;                
        }
        if(s1[len1-1]==0 || s2[len1-1]==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    system("pause");
    return 0;
}
