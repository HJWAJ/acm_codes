#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    __int64 r,ans=1,n;
    scanf("%I64d",&r);
    if(r==1){printf("1\n");exit(0);}
    n=r/2;
    ans+=(6*n*(n-1)/2);
    ans+=(6*(r-n-1));
    printf("%I64d\n",ans);
    
    //system("pause");    
    return 0;
}
