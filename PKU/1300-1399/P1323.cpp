#include<iostream>
#include<algorithm>
using namespace std;

bool val[1000000];
int main()
{
    int m,n,p,a[100],i,cnt1,cnt,t=0;
    while(cin>>m>>n && (m!=0 || n!=0))
    {
        memset(val,0,sizeof(val));
        t++;
        p=m*n;
        cnt=0;
        cnt1=0;
        for(i=0;i<n;i++){cin>>a[i];val[a[i]]=1;}
        for(i=p;i>=1;i--)
        {
            if(cnt1==0 && val[i]==1)cnt++;
            else if(cnt1!=0 && val[i]==1)cnt1--;
            else cnt1++;                 
        }
        
        
        cout<<"Case "<<t<<": "<<cnt<<endl;              
    }
    
    system("pause");
    return 0;
}
