#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int rev(int n)
{
    int nn=0;
    while(n)
    {
        nn*=10;
        nn+=(n%10);
        n/=10;        
    }
    return nn;    
}

bool isrev(int n)
{
    if(rev(n)==n)return 1;
    return 0;     
}

int main()
{
    freopen("1.txt","w",stdout);
    int i,j;
    for(i=2;i<=100000;i++)
        for(j=2;j<=100000;j++)
            if(i*j==rev(i)*rev(j) && (!isrev(i) && !isrev(j)))printf("%d %d\n",i,j);
    
    //system("pause");
    return 0;
}
