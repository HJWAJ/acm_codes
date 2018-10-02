#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[8]="ROYGBIV";
    int n,div,mod,i;
    scanf("%d",&n);
    n-=7;
    printf("ROYGBIV");
    div=n/4;
    mod=n%4;
    if(div==0)
    {
        for(i=0;i<mod;i++)printf("%c",s[i+3]);          
    }
    else
    {
        for(i=0;i<div;i++)printf("ROYG");
        for(i=0;i<mod;i++)printf("%c",s[i+4]);
    }
    printf("\n");
    
    //system("pause");    
    return 0;
}
