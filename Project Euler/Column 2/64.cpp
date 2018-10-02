//Ä£Äâ 

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<windows.h>
using namespace std;
int a[10005];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int i,j,k,cnt=0,num,den,zn,flag,d;
    double sq;
    for(i=1;i<10001;i++)
    {
        k=0;
        sq=sqrt(i);
        if(sq==(int)sq)continue;
        a[0]=(int)sq;
        den=a[0];
        num=i-a[0]*a[0];
        zn=1;
        flag=0;
        while(!flag)
        {
            sq=zn*(a[0]+den)/num;
            j=(int)sq;
            k++;
            if(j==2*a[0])flag=1;
            a[k]=j;
            if(flag)break;
            den-=a[k]*num;
            swap(den,num);
            zn=den;
            den=-num;
            num=i-num*num;
            d=gcd(zn,num);
            zn/=d;
            num/=d;
        }
        if(k&1)cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
