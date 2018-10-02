#include<iostream>
using namespace std;

int main()
{
    char s1[20],s2[20],s3[20];
    while(cin>>s1>>s2 && (s1[0]!='0' || s2[0]!='0'))
    {
        memset(s3,0,sizeof(s3));
        int len1=strlen(s1);
        int len2=strlen(s2);
        int cnt=0;
        int i,len;
        if(len1>len2)len=len1;
        else len=len2;
        for(i=0;i<len1/2;i++)swap(s1[i],s1[len1-1-i]);
        for(i=0;i<len2/2;i++)swap(s2[i],s2[len2-1-i]);
        for(i=0;i<len;i++)
        {
            s3[i]=s3[i]+s1[i]+s2[i]-'0';
            if(s1[i]=='\0' || s2[i]=='\0')s3[i]+='0';
            if(s3[i]>'9'){s3[i+1]++;cnt++;}                  
        }
        if(cnt==0)cout<<"No carry operation."<<endl;
        else if(cnt==1)cout<<cnt<<" carry operation."<<endl;
        else cout<<cnt<<" carry operations."<<endl; 
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));                 
    }    
    
    system("pause");
    return 0;
}
