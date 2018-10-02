#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int p[4],a,b,num,i;
    for(i=0;i<4;i++)scanf("%d",p+i);
    scanf("%d%d",&a,&b);
    num=0;
    for(i=a;i<=b;i++)
    {
        if(i==(i%p[0]%p[1]%p[2]%p[3]))num++;                
    }    
    printf("%d\n",num);
    
    return 0;
}
