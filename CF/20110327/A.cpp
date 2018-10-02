#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,p=1,i;
    scanf("%d",&n);    
    for(i=0;i<n-1;i++)
    {
        p*=3;
        p%=1000003;                  
    }
    printf("%d\n",p);
    //system("pause");
    return 0;
}
