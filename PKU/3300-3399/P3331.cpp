#include<iostream>
using namespace std;

void multi(int a[],int n)
{
    int i;
    for(i=0;i<1000;i++)a[i]*=n;
    for(i=0;i<1000;i++)
    {
        a[i+1]+=(a[i]/10);
        a[i]%=10;
    }
}

int main()
{
    int a[1005],t,n,num,len,cnt,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>num;
        memset(a,0,sizeof(a));
        a[0]=1;
        cnt=0;
        for(i=1;i<=n;i++)multi(a,i);
        for(len=1000;len>=0;len--)
            if(a[len])break;
        for(i=0;i<=len;i++)
            if(a[i]==num)cnt++;
        cout<<cnt<<endl;
    }
        
    return 0;
}
