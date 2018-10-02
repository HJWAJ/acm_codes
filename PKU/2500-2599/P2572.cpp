#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[30];
    while(cin>>s)
    {
        int a[7],b[7],c[8],aa=0,bb=0,cc=0,sum=0;
        int i=0,j=0,m,n,p,len=strlen(s);
        while(s[i++]!='+')
        {
            a[j++]=s[i-1]-'0';                  
        }   
        m=j-1;j=0;           
        while(s[i++]!='=')
        {
            b[j++]=s[i-1]-'0';                  
        }
        n=j-1;j=0;
        for(;i<len;i++)c[j++]=s[i]-'0';
        p=j-1;
        for(i=0;i<=m;i++)
        {
            aa*=10;
            aa+=a[m-i];                
        }
        for(i=0;i<=n;i++)
        {
            bb*=10;
            bb+=b[n-i];                
        }
        for(i=0;i<=p;i++)
        {
            cc*=10;
            cc+=c[p-i];                
        }
        sum=aa+bb;
        if(sum==cc)cout<<"True"<<endl;
        else cout<<"False"<<endl;
        if(strcmp(s,"0+0=0")==0)break;
    }
    
    
    system("pause");
    return 0;
}
