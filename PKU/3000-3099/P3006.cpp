#include<iostream>
using namespace std;

//int sushu[200000];
bool dabiao[1000001];

void sushubiao()
{
    //memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num,i,j;
      
    for(i=2;i<=1000000;i++)
        for(j=2;j<=1000000/i;j++)
            dabiao[j*i]=1;  
    
    j=0;
    //for(i=2;i<=1000000;i++)if(dabiao[i]==0){sushu[j]=i;j++;}
} 


int main()
{
    sushubiao();
    int m,n,p;
    int i;
    while(cin>>m>>n>>p && (m!=0 || n!=0 || p!=0))
    {
        i=0;
        for(;;)
        {
            if(dabiao[m]==0)i++;
            if(i==p)break;
            m+=n;
        } 
        cout<<m<<endl;                  
    }    
    
    system("pause");
    return 0;
}
