#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s1[100001],s2[100001];
    while(cin>>s1>>s2)
    {
        int i=0,j,len1=strlen(s1),len2=strlen(s2);
        for(j=0;j<len2;j++)
        {
            if(s1[i]==s2[j])
            {
                s1[i]=0;
                i++;
                if(i==len1)break;
            }                         
        }   
        if(s1[len1-1]==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;               
    }    
    
    system("pause");
    return 0;
}
