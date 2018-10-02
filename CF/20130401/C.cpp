#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,foo=0,bar=0,baz=0,quz=1,pur;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&pur);
        foo+=pur;
        bar+=1;
        if(max(foo*quz,bar*baz)==foo*quz)
        {
            baz=foo;
            quz=bar;
        }
    }
    printf("%.6lf\n",baz*1.0/quz);
    return 0;
}
