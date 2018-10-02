#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,bin[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576},i,flag1,flag2;
    bool a[21];
    while(cin>>n && n!=0)
    {
        memset(a,0,sizeof(a));
        for(i=20;i>=0;i--)
        {
            n-=bin[i];
            a[i]=1;
            if(n<0){n+=bin[i];a[i]=0;}
            if(n==0)break;                 
        }
        
       
        for(i=0;i<=20;i++)
        {
            if(a[i]==1){flag1=i;a[i]=0;break;}                  
        }
        
        for(i=flag1+1;i<=20;i++)
        {
            if(a[i]==0){flag2=i;a[i]=1;break;}                    
        }
        
        for(i=0;i<flag2-flag1-1;i++)a[i]=1;
        for(i=flag2-flag1-1;i<flag2;i++)a[i]=0;
       
        n=0;
        for(i=20;i>0;i--)
        {
            n+=a[i];
            n*=2;                  
        }
        n+=a[0];
        cout<<n<<endl;
    }    
    
    system("pause");
    return 0;
}
