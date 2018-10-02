#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool equal(double a[],int n)
{
    int i;
    for(i=0;i<n-1;i++)
        if(a[i]!=a[i+1])return 0;
    return 1;
}

int main()
{
    int n,k,flagl,flagr,i;
    double a[1005],aa,bb,tmp;
    memset(a,0,sizeof(a));
    cin>>n>>k;
    flagl=0;flagr=n-1;
    for(i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    while(!equal(a,n))
    {
        while(a[flagl]==a[flagl+1])flagl++;
        while(a[flagr]==a[flagr-1])flagr--;
        if(flagl==flagr-1)
        {
            double tmp1=a[n-1]*(n-flagr)*(1-k/100.0)+a[0]*(flagl+1);
            double tmp2=(flagl+1+(n-flagr)*(1-k/100.0));
            a[0]=tmp1/tmp2;
            break;                 
        }
        aa=(flagl+1)*(a[flagl+1]-a[flagl]);
        bb=(n-flagr)*(a[flagr]-a[flagr-1]);
        if(aa>=bb*(1-k/100.0))
        {
            tmp=bb*(1-k/100.0)/(flagl+1);
            for(i=0;i<=flagl;i++)a[i]+=tmp;
            for(i=n-1;i>=flagr;i--)a[i]=a[flagr-1];
            flagr--;
            if(aa==bb*(1-k/100.0))flagl++;          
        }
        else
        {
            tmp=aa/(1-k/100.0)/(n-flagr);
            for(i=0;i<=flagl;i++)a[i]=a[flagl+1];
            for(i=n-1;i>=flagr;i--)a[i]-=tmp;
            flagl++;    
        }  
    }
    cout<<setprecision(15)<<a[0]<<endl;    
    //system("pause");
    return 0;
}
