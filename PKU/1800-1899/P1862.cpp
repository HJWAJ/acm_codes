#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int t,a[1000],i;
    double s;
    cin>>t;
    for(i=0;i<t;i++)cin>>a[i];
    sort(a,a+t);
    s=double(a[t-1]);
    for(i=t-2;i>=0;i--)    
    {
        s=2*sqrt(double(a[i]*s));                       
    }
    printf("%.3lf\n",s);
    
    system("pause");
    return 0;
}
