#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    double a,b,c,d,cc,dd;
    int cnt1,cnt2;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF)
    {
        cc=c;
        dd=d;
        cnt1=cnt2=0;
        while(c>a){c/=2;cnt1++;}
        while(d>b){d/=2;cnt1++;}
        while(cc>b){cc/=2;cnt2++;}
        while(dd>a){dd/=2;cnt2++;}
        if(cnt1>cnt2)printf("%d\n",cnt2);
        else printf("%d\n",cnt1);                             
    }    
    
    return 0;
}
