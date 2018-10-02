#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
    int n,i,j,num;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>199)
        {
            puts("0");
            continue;
        }
        num=0;
        for(i=0;i<100;i++)
            for(j=0;j<100;j++)
                if(n-i-j==0)
                    num++;
        printf("%d\n",num);
    }
    return 0;
}
