#include<iostream>
using namespace std;

int sushu[50000];
bool dabiao[200001];

void sushubiao()
{
    int i,j;
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
      
    for(i=2;i<=50000;i++)
        for(j=2;j<=50000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=2;i<=50000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 

int main()
{
    sushubiao();
    int n,k,i,max,maxk=1;
    cin>>n;
    max=0;
    while(n--)
    {
        cin>>k;
        i=0;
        while(sushu[i]<=k)
        {
            if(k%sushu[i]==0 && max<sushu[i]){max=sushu[i];maxk=k;}
            i++;
        }          
    }    
    cout<<maxk<<endl;
    
    system("pause");
    return 0;
}
