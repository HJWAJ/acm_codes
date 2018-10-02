#include<iostream>
#include<cmath>
using namespace std;

long long int k,t;

long long int extended_euclid(long long int a,long long int b)
{
    if(b==0) // gcd(a, b) == a
    {
        k=1;
        t=0;
        return a;
    }
    long long int n=extended_euclid(b,a%b);
    long long int tmp=k;
    k=t;
    t=tmp-(a/b)*t;
    return n;
}

int main()
{
    long long int x,y,m,n,l,gcd,d,v;
    long long int cnt=0,i=1;
    cin>>x>>y>>m>>n>>l;
    v=m-n;
    d=y-x;
    if(v<0){v=-v;d=-d;}
    gcd=extended_euclid(v,l);
    if(d%gcd!=0)cout<<"Impossible"<<endl;
    else
    {
        t=t*d/gcd;
        k=k*d/gcd;
        l=l/gcd;
        if(k>=0)k%=l;
        else k=k%l+l;
        cout<<k<<endl;    
    }
    
    system("pause");
    return 0;
}
