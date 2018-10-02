#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,i;
    double a0,a1,an,c[100000];
    scanf("%d%lf%lf",&n,&a0,&an);
    for(i=0;i<n;i++)scanf("%lf",&c[i]);
    a1=n*a0+an;
    for(i=0;i<n;i++)
        a1-=(2*(n-i)*c[i]);
    a1/=(n+1);
    printf("%.2lf\n",a1);
    
    system("pause");
    return 0;
}
