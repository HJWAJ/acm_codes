#include<iostream>
#include<cstdio>
#include<cmath>
#define PI acos(-1.0)
using namespace std;

int main()
{
    int t,n,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        double R,r;
        scanf("%lf%d",&R,&n);
        r=(double)(R/(1+(1/sin(PI/n))));
        printf("Scenario #%d:\n",i);
        printf("%.3f\n\n",r);
    }
    
    system("pause");
    return 0;
}

