#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int a,n,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        while(n--)
        {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
