#include<iostream>
#include<cstring>
using namespace std;

int a1[1000],a2[1000],a3[2000];

int multi(int *a1,int *a2,int p,int q)
{
    int i,j;
    memset(a3,0,sizeof(a3));
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            a3[i+j]=a3[i+j]+a1[i]*a2[j];
            
    for(i=0;i<p+q;i++)
        if(a3[i]>=10){a3[i+1]=a3[i+1]+a3[i]/10;a3[i]%=10;}  
    i=p+q;
    while(a3[i]==0)i--;
    return i;  
}

int main()
{
    int i,j;
    char s1[1000],s2[1000];
    cin>>s1>>s2;
    int len1=strlen(s1);
    int len2=strlen(s2);
    for(i=len1-1;i>=0;i--)a1[i]=s1[len1-1-i]-'0';
    for(i=len2-1;i>=0;i--)a2[i]=s2[len2-1-i]-'0';
    int len=multi(a1,a2,len1,len2);    
    for(i=len;i>=0;i--)cout<<a3[i];
    cout<<endl;
    
    system("pause");
    return 0;
}
