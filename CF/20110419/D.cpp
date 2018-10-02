#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,a,b;
    double s,s1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(b==0)printf("1.0\n");
        else if(a==0)printf("0.5\n");
        else printf("%lf\n",0.5+a/16.0/b);
    }
    
    //system("pause");
    return 0;
}
