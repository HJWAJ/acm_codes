#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char s[100];
    int flag,k=0;
    cin>>s;
    while(s[0]!='#')
    {
        flag=strlen(s)-1;
        while(s[flag]<=s[flag-1])flag--;
        if(flag==0){cout<<"No Successor"<<endl;goto label;}
        else
        {
            while(s[flag-1]<s[flag+k])k++; 
            //if(flag+k==strlen(s))
            {
                swap(s[flag-1],s[flag+k-1]);
                sort(s+flag,s+strlen(s));
            }
            /*else 
            {
                 swap(s[flag-1],s[flag+k]);
                 sort(s+flag,s+strlen(s));
            }  */ 
        }                
        cout<<s<<endl;
label:        cin>>s;
    }    
    
    
    system("pause");
    return 0;
}
