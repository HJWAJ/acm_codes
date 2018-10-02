#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

int min(int a,int b)
{
    if(a>b)return b;
    return a;    
}

int main()
{
    int n,x1,y1,x2,y2,dis;
    while(scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2)!=EOF)
    {
        if((x1==0 && x2==0) || (x1==n && x2==n) || (y1==n && y2==n) || (y1==0 && y2==0))dis=abs(x1-x2)+abs(y1-y2);    
        if((x1==0 && y2==n) || (y1==n && x2==0))dis=x1+x2+n-y1+n-y2;
        if((y1==0 && x2==n) || (y2==0 && x1==n))dis=n-x1+n-x2+y1+y2;
        if((y1==n && x2==n) || (y2==n && x1==n))dis=4*n-x1-x2-y1-y2;
        if((x1==0 && y2==0) || (y1==0 && x2==0))dis=x1+x2+y1+y2;
        if((x1==0 && x2==n) || (x1==n && x2==0))dis=n+min(y1+y2,2*n-y1-y2);
        if((y1==0 && y2==n) || (y1==n && y2==0))dis=n+min(x1+x2,2*n-x1-x2);
        printf("%d\n",dis);
    }    
    
    return 0;
}
