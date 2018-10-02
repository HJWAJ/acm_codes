#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    if(!(n&1))printf("Marsel\n");
    else printf("Timur\n");
    
    system("pause");    
    return 0;
}
