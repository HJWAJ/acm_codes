#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b,n,tmp;
    scanf("%d%d%d",&a,&b,&n);
    while(1)
    {
        tmp=gcd(a,n);
        if(n<tmp)
        {
            puts("1");
            break;
        }
        n-=tmp;
        tmp=gcd(b,n);
        if(n<tmp)
        {
            puts("0");
            break;
        }
        n-=tmp;
    }
	return 0;
}
