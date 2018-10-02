#include<iostream>
using namespace std;

int sushu[50000];
bool dabiao[200001];

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j;  
    for(i=2;i<=50000;i++)
        for(j=2;j<=50000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    for(i=2;i<=50000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 

int main()
{
    sushubiao();
    int n;
    while(cin>>n && n!=0)
    {
        int i=0,k=0;
        //if(dabiao[n]==0)cout<<1<<endl;
        //else
        {
            int m=n;
            while(sushu[i]<=m)
            {
                int j=i;
                n=m;
                while(n>=sushu[j])
                {
                    n-=sushu[j];
                    j++;          
                } 
                if(n==0)k++;
                i++;           
            } 
            cout<<k<<endl;
        }
    }    
    
    system("pause");
    return 0;
}
