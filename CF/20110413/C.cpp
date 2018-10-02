#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int gcd(int m,int n)
{
    if(n==0)return m;
    return gcd(n,m%n);    
}

int main()
{
    int a,b,l,u,n,i,res,sq,num[100005],flag=0;
    scanf("%d%d%d",&a,&b,&n);
    res=gcd(a,b);
    sq=int(sqrt(double(res)));
    for(i=1;i<=sq;i++)
        if(res%i==0)
        {
            num[flag++]=i;
            num[flag++]=res/i;
        }
    sort(num,num+flag);
    while(n--)
    {
        scanf("%d%d",&l,&u);
        for(i=flag-1;i>=0;i--)
            if(num[i]>=l && num[i]<=u)
            {
                printf("%d\n",num[i]);
                break;             
            }         
        if(i<0)printf("-1\n"); 
    }
    
    //system("pause");   
    return 0;
}
