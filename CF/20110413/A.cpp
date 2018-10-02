#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

__int64 rev(__int64 n)
{
    __int64 nn=0;
    while(n)
    {
        nn*=10;
        nn+=(n%10);
        n/=10;        
    }
    return nn;
}

int main()
{
    __int64 a,b,c,aa,bb,cc,a1,b1,c1;
    scanf("%I64d%I64d",&a,&b);
    c=a+b;
    a1=a;b1=b;c1=c;
    aa=bb=cc=0;
    while(a1)
    {
        if(a1%10==0)a1/=10;
        else
        {
            aa*=10;
            aa+=(a1%10);
            a1/=10;    
        }         
    }
    aa=rev(aa);
    while(b1)
    {
        if(b1%10==0)b1/=10;
        else
        {
            bb*=10;
            bb+=(b1%10);
            b1/=10;    
        }         
    }
    bb=rev(bb);
    while(c1)
    {
        if(c1%10==0)c1/=10;
        else
        {
            cc*=10;
            cc+=(c1%10);
            c1/=10;    
        }
    }
    cc=rev(cc);
    if(aa+bb==cc)printf("YES\n");
    else printf("NO\n");
    //while(1);
    return 0;
}
