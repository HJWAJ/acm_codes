#include<iostream>
using namespace std;

int main()
{
    int sushu[50000];
    bool dabiao[200001];
    int i,j,n;
    dabiao[0]=1;
    dabiao[1]=1;
      
    for(i=2;i<=50000;i++)
        for(j=2;j<=50000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=3;i<=50000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
        
    while(cin>>n && n!=0)
    {
        j=0;
        for(i=0;i<n;i++)
        {
            if(sushu[i]>n)break;
            if(dabiao[n-sushu[i]]==0)j++;                
        }             
        if(j%2==0)j/=2;
        else j=j/2+1;
        cout<<j<<endl;
    }
    
    system("pause");
    return 0;
}
