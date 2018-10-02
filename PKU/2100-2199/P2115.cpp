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

long long int pow2(long long int n)
{
    long long int l=1LL;
    while(n--)l<<=1;
    return l;     
}

int main()
{
    long long int a,b,c,n,gcd,d,v,l;
    long long int cnt=0,i=1;
    while(cin>>a>>b>>c>>n && !(a==0 && b==0 && c==0 && n==0))
    {
        if(c==0)
        {
            if(a==b)cout<<0<<endl;
            else cout<<"FOREVER"<<endl;
            continue;        
        }
        v=c;
        d=b-a;
        l=pow2(n);
        if(v<0){v=-v;d=-d;}
        gcd=extended_euclid(v,l);
        if(d%gcd!=0)cout<<"FOREVER"<<endl;
        else
        {
            t=t*d/gcd;
            k=k*d/gcd;
            l=l/gcd;
            if(k>=0)k%=l;
            else k=k%l+l;
            cout<<k<<endl;    
        }
    }
    
    system("pause");
    return 0;
}
