#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,n,score,i;
    char s[100];
    while(scanf("%d%d",&t,&n) && t!=0)
    {
        n*=3;
        for(i=0;i<t;i++)
        {
            scanf("%s%d",s,&score);
            n-=score;
        }
        printf("%d\n",n);                          
    }    
    
    return 0;
}
