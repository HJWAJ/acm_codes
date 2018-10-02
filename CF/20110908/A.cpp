#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,m,cnt=0,flag=0;
    scanf("%d%d",&n,&m);
    while(m>1)
    {
        if(m%n)
        {
            puts("NO");
            flag=1;
            break;
        }
        else
        {
            m/=n;
            cnt++;
        }
    }
    if(!flag)
    {
        puts("YES");
        printf("%d\n",cnt-1);
    }
    return 0;
}
