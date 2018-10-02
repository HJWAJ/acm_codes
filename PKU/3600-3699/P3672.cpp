#include<iostream>
using namespace std;

int main()
{
    int m,t,u,f,d,i;
    cin>>m>>t>>u>>f>>d;
    char s[100005];
    for(i=0;i<t;i++)cin>>s[i];
    i=0;
    while(m>=0)
    {
        if(s[i]=='u' || s[i]=='d')m-=(u+d);
        else m-=(2*f);
        i++;           
    }    
    cout<<i-1<<endl;
    
    system("pause");
    return 0;
}
