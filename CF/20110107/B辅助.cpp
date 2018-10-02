#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    freopen("1.txt","w",stdout);
    int i,p=1;
    for(i=0;i<32;i++)
    {
        printf("%d,",p);
        p*=2;                 
    }
    return 0;
}
