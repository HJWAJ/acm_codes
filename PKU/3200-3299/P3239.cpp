#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int n,i,k;
    while(scanf("%d",&n) && n)
    {
        if(n%6!=2 && n%6!=3)
        {
            printf("2");
            for(i=4;i<=n;i+=2)printf(" %d",i);
            for(i=1;i<=n;i+=2)printf(" %d",i);
            puts("");
        }
        else
        {
            k=n/2;
            printf("%d",k);
            if(k&1)
            {
                for(i=k+2;i<n;i+=2)printf(" %d",i);
                for(i=1;i<k;i+=2)printf(" %d",i);
                for(i=k+3;i<=n;i+=2)printf(" %d",i);
                for(i=2;i<k+2;i+=2)printf(" %d",i);
            }
            else
            {
                for(i=k+2;i<=n;i+=2)printf(" %d",i);
                for(i=2;i<k;i+=2)printf(" %d",i);
                for(i=k+3;i<n;i+=2)printf(" %d",i);
                for(i=1;i<k+2;i+=2)printf(" %d",i);
            }
            if(n&1)printf(" %d",n);
            puts("");
        }
    }
	return 0;
}
