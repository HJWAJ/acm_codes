#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<queue>
#include<string>
#include<vector>
using namespace std;
int main()
{
    __int64 n,a,b,c,a1,b1,n1,tmp;
    __int64 min=999999999999999999LL,max=-1;
    scanf("%I64d",&n);
    for(a1=1;a1*a1<=n;a1++)
    {
        if(n%a1==0)
        {
            n1=n/a1;
            a=a1+1;
            for(b1=1;b1*b1<=n1;b1++)
            {
                if(n1%b1==0)
                {
                    b=b1+2;
                    c=n1/b1+2;
                    tmp=2*a*b+2*a*c-4*a+b*c-2*b-2*c+4;
                    min=min<tmp?min:tmp;
                    max=max>tmp?max:tmp;
                }
            }
            a=n1+1;
            for(b1=1;b1*b1<=a1;b1++)
            {
                if(a1%b1==0)
                {
                    b=b1+2;
                    c=a1/b1+2;
                    tmp=2*a*b+2*a*c-4*a+b*c-2*b-2*c+4;
                    min=min<tmp?min:tmp;
                    max=max>tmp?max:tmp;
                }
            }
        }
    }
    printf("%I64d %I64d\n",min,max);
    return 0;
}
