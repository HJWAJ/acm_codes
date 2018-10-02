#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[1001];
        cin>>s;
        int len=strlen(s);
        int i,cnt[1000],count=0;
        char ch[1000];
        ch[0]=s[0];
        cnt[0]=1;
        for(i=1;i<len;i++)
        {
            if(s[i]==ch[count])cnt[count]++;
            else {count++;ch[count]=s[i];cnt[count]=1;}         
        }          
        for(i=0;i<=count;i++)cout<<cnt[i]<<ch[i];
        cout<<endl;
    }    
    
    system("pause");
    return 0;
}
