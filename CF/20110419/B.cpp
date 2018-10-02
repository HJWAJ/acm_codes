#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int h,min;
    double a,b;
    char p;
    scanf("%d%c%d",&h,&p,&min);
    a=(h*60+min)*0.5;
    if(a>=360.0)a-=360.0;
    b=min*6.0;
    if(b>=360.0)b-=360.0;
    printf("%lf %lf\n",a,b);
    
    //system("pause");
    return 0;
}
