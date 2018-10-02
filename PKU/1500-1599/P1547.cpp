#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,i,a,b,h,v[100],max,min,p,q;
    char s[100][100];
    while(cin>>n && n!=-1)
    {
        max=-1;min=999999;
        for(i=0;i<n;i++)
        {
            cin>>a>>b>>h;
            cin>>s[i];
            v[i]=a*b*h;                
        } 
               
        for(i=0;i<n;i++)
        {
            if(v[i]>max){max=v[i];p=i;}
            if(v[i]<min){min=v[i];q=i;}                
        }
        cout<<s[p];
        cout<<" took clay from ";
        cout<<s[q];
        cout<<'.'<<endl;
        memset(s,0,sizeof(s));
        memset(v,0,sizeof(v));
    }
    
    
    system("pause");
    return 0;
}
