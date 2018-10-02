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
#include<windows.h>
using namespace std;
int n,k;
int main()
{
    int cnt,num,flag,i,x,bo;
    scanf("%d%d",&n,&k);
    num=k/2+1;
    while(n)
    {
        bo=0;
        flag=cnt=0;
        i=num-1;
        x=0;
        while(n>=k && cnt<k)
        {
            bo=1;
            cnt++;
            if((k&1) && !flag)
            {
                flag=1;
                printf("%d\n",num);
                continue;
            }
            if(k&1)
            {
                if(x)printf("%d\n",num+num-i);
                else printf("%d\n",i);
            }
            else
            {
                if(x)printf("%d\n",num+num-1-i);
                else printf("%d\n",i);
            }
            x^=1;
            if(!x)i--;
        }
        if(bo)n-=k;
        if(n && n<k)
        {
            x=flag=cnt=0;
            i=num-1;
            while(cnt<n)
            {
                cnt++;
                if((k&1) && !flag)
                {
                    flag=1;
                    printf("%d\n",num);
                    continue;
                }
                if(k&1)
                {
                    if(x)printf("%d\n",num+num-i);
                    else printf("%d\n",i);
                }
                else
                {
                    if(x)printf("%d\n",num+num-1-i);
                    else printf("%d\n",i);
                }
                x^=1;
                if(!x)i--;
            }
            break;
        }
    }
    return 0;
}
