#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n[10000],i=0,flag1=0,flag2=0,judge=1,m;
    char s[20000][10];
    
    cin>>n[i];
    while(n[i]!=0)
    {
        cin>>s[2*i]>>s[2*i+1];
        cin>>n[i+1];
        i++;          
    }   
    m=i; 
    
    while(flag1<m && flag2<m)
    {
    i=flag1;
    while(strcmp(s[2*i],"right")!=0)i++;
    flag2=i;
    
    for(i=flag1;i<flag2;i++)
    {
        if((strcmp(s[2*i+1],"high")==0 && n[i]<=n[flag2]) || (strcmp(s[2*i+1],"low")==0 && n[i]>=n[flag2])){judge=0;break;}                   
    }
    flag1=flag2+1;
    
    if(judge==0)cout<<"Stan is dishonest"<<endl;
    else cout<<"Stan may be honest"<<endl;
    judge=1;
    }
    
    system("pause");
    return 0;
}
