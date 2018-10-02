#include<iostream>
#include<cstring>
using namespace std;

int sushu[200000];
bool dabiao[2000000];

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j;  
    for(i=2;i<=2000000;i++)
        for(j=2;j<=2000000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=2;i<=2000000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 


int main()
{
    sushubiao();
    int n;
    while(cin>>n && n!=0)
    {
        if(n==1 || dabiao[n]==0)cout<<0<<endl;
        else 
        {
            int i=1;
            while(sushu[i]<n)i++;
            int t;
            t=sushu[i]-sushu[i-1];
            cout<<t<<endl;     
        }             
    }
    
    system("pause");
    return 0;
}
