#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int i,j,k,p,num[5];
    bool a[30000];
    memset(a,0,sizeof(a));
    
    for(i=1;i<=10000;i++)
    {
        k=i;
        p=i;
        for(j=0;j<5;j++)
        {
            num[j]=k%10;
            k/=10;
            p+=num[j];
        }   
        a[p-1]=1;                 
    }
    
    for(i=0;i<10000;i++)
    {
        if(a[i]==0)cout<<i+1<<endl;                
    }    
    
    system("pause");
    return 0;
}
