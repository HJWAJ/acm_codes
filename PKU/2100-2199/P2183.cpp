#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[1000001];
int main()
{
    int n,i=0;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    while(1)
    {
        if(!a[n])a[n]=i;
        else
        {
            printf("%d %d %d\n",n,i-a[n],i);
            break;
        }
        n=n%100000/10;
        n*=n;
        n%=1000000;
        i++;
    }
    return 0;
}
