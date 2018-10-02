#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,i,x,y,z,sum1,sum2,sum3;
    scanf("%d",&n);
    sum1=sum2=sum3=0;
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        sum1+=x;
        sum2+=y;
        sum3+=z;   
    }
    if(sum1 || sum2 || sum3)printf("NO\n");
    else printf("YES\n");
    
    return 0;
}
