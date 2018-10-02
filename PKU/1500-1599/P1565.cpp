#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    long long int bin[31];
    __int64 sum;
    int i;
    char s[100],ss[100];
    bin[0]=2;
    for(i=1;i<30;i++)
    {
        bin[i]=bin[i-1]*2;  
        bin[i-1]-=1;               
    }    
    bin[30]=2147483647;
    bin[29]--;
    bin[0]=1;
    
    
    while(cin>>s && strcmp(s,"0")!=0)
    {
         sum=0;
         for(i=0;i<strlen(s);i++)sum=sum+(s[strlen(s)-1-i]-'0')*bin[i];    
         cout<<sum<<endl;        
    }
    
    system("pause");
    return 0;
}
