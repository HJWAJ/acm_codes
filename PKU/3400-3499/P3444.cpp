#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int i,j,n,a[256],b[256],m,p;
    while(scanf("%d",&n) && n!=0)
    {
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        m=int(log(double(n))/log(2.0)+0.5);
        for(i=0;i<m;i++)
        {
            p=int(pow(2.0,double(i+1)))/2;
            for(j=0;j<p;j++)
            {
                b[j*2]=(a[j]+a[j+p])/2;
                b[j*2+1]=(a[j]-a[j+p])/2;
            }       
            for(j=0;j<2*p;j++)a[j]=b[j];
        }                     
        for(i=0;i<n;i++)printf("%d ",a[i]);
        printf("\n");
    }    
    
    system("pause");
    return 0;
}
