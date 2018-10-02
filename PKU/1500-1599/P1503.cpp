#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[100][1000];
    int sum[1000];
    memset(sum,0,sizeof(sum));
    int i=0,len=0,n,j;
    
    cin>>s[i];
    while(strcmp(s[i],"0")!=0)
    {
        cin>>s[++i];                          
    }   
    n=i;
    /*
    for(i=0;i<n;i++)
    {
        if(strlen(s[i])>len)len=strlen(s[i]);                
    } 
    
    len+=3;
    */
    //for(i=0;i<strlen(s[0]);i++)s[0][i]-='0';
    
    for(i=0;i<n;i++)
        for(j=strlen(s[i])-1;j>=0;j--)
        {
            sum[1000-strlen(s[i])+j]=sum[1000-strlen(s[i])+j]+s[i][j]-'0';
            if(sum[1000-strlen(s[i])+j]>=10)
            {
                sum[1000-strlen(s[i])+j]-=10;
                sum[999-strlen(s[i])+j]++;                              
            }                              
        }
        
    //for(i=0;i<1000;i++)sum[i]+='0';
    
    i=0;
    while(sum[i]==0)i++;
    for(j=i;j<1000;j++)cout<<sum[j];
    cout<<endl;
    
    system("pause");
    return 0;
}
