#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,a[10000],i,time;   
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    time=0;
    for(i=n-1;i>=3;i-=2)
    {
        if(a[1]*2>=a[0]+a[i-1])time=time+a[0]*2+a[i]+a[i-1];
        else time=time+a[1]*2+a[i]+a[0];                  
    }
    if(i==2)time=time+a[0]+a[1]+a[2];
    if(i==1)time+=a[1];
    if(i==0)time+=a[0];
    printf("%d\n",time);
    
    system("pause");
    return 0;
}
