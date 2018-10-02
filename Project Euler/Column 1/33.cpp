#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
int a[2][4];
int p=1,q=1,d;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,cnt=0;
    for(i=10;i<100;i++)
        for(j=i+1;j<100;j++)
            if(i/10*j==j%10*i && i%11 && i%10==j/10)
            {
                a[0][cnt]=i;
                a[1][cnt]=j;
                cnt++;
            }
    for(i=0;i<4;i++)
    {
        p*=a[0][i];
        q*=a[1][i];
    }
    d=gcd(p,q);
    p/=d;
    q/=d;
    cout<<p<<'/'<<q<<endl;//q is the value to solve
    return 0;
}
