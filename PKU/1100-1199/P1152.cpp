#include<iostream>
using namespace std;

char s[1000000];
int a[1000000];

int main()
{
    while(cin>>s)
    {
        int len=strlen(s);
        int max=0,sum=0;
        int i;
        for(i=0;i<len;i++)
        {
            if(s[i]>='0' && s[i]<='9')a[i]=s[i]-'0';
            else if(s[i]>='A' && s[i]<='Z')a[i]=s[i]-'A'+10;
            else a[i]=s[i]-'a'+36;
            sum+=a[i];
            if(max<a[i])max=a[i];                      
        }
        for(i=max;i<62;i++)
            if(sum%i==0){cout<<i+1<<endl;break;}
        if(i==62)cout<<"such number is impossible!"<<endl;     
    }    
    
    system("pause");
    return 0;
}
