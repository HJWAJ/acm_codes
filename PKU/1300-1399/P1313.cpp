#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int main()
{
    int n,i,k;
    while(scanf("%d",&n) && n)
    {
        printf("Printing order for %d pages:\n",n);
        k=n/4+1;
        if(n%4==1)
        {
            if(n==1)puts("Sheet 1, front: Blank, 1");
            else
            {
                puts("Sheet 1, front: Blank, 1");
                puts("Sheet 1, back : 2, Blank");
                puts("Sheet 2, front: Blank, 3");
                printf("Sheet 2, back : 4, %d\n",n);
                for(i=3;i<=k;i++)
                {
                    printf("Sheet %d, front: %d, %d\n",i,n+5-i*2,2*i-1);
                    printf("Sheet %d, back : %d, %d\n",i,2*i,n+4-i*2);
                }
            }
        }
        else if(n%4==2)
        {
            puts("Sheet 1, front: Blank, 1");
            puts("Sheet 1, back : 2, Blank");
            for(i=2;i<=k;i++)
            {
                printf("Sheet %d, front: %d, %d\n",i,n+4-i*2,2*i-1);
                printf("Sheet %d, back : %d, %d\n",i,2*i,n+3-i*2);
            }
        }
        else if(n%4==3)
        {
            puts("Sheet 1, front: Blank, 1");
            printf("Sheet 1, back : 2, %d\n",n);
            for(i=2;i<=k;i++)
            {
                printf("Sheet %d, front: %d, %d\n",i,n+3-i*2,2*i-1);
                printf("Sheet %d, back : %d, %d\n",i,2*i,n+2-i*2);
            }
        }
        else
        {
            k--;
            for(i=1;i<=k;i++)
            {
                printf("Sheet %d, front: %d, %d\n",i,n+2-i*2,2*i-1);
                printf("Sheet %d, back : %d, %d\n",i,2*i,n+1-i*2);
            }
        }
    }
    return 0;
}
