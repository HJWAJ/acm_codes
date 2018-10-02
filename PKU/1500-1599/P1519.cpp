#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[1000];
    cin>>s;
    while(s[0]!='0')
    {
        int a,i,sum=0,n=0;
        for(i=0;i<strlen(s);i++)n=n+s[i]-'0';
        while(n>=10)
        {
            a=n%10;
            n/=10;
            sum+=a;
        }
        sum+=n;
        while(sum>=10)
        {
            n=sum;
            sum=0;
            while(n>=10)
            {
                a=n%10;
                n/=10;
                sum+=a;
            }    
            sum+=n;
        }           
        cout<<sum<<endl; 
        cin>>s;            
    }
    
    
    system("pause");
    return 0;
}
