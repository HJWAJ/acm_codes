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
int a[105];
int main()
{
    int n,i,ansn,time=0,per=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    int sum=0,flag=0;
    while(sum<=350)
    {
        sum+=a[flag];
        flag++;
    }
    time=sum-350;
    ansn=flag;
    if(time>360)
    {
        flag--;
        printf("%d 0\n",flag);
        return 0;
    }
    else
    {
        per=time;
        while(time<=360)
        {
            if(a[flag]+time>360)
            {
                printf("%d %d\n",flag,per);
                break;
            }
            else
            {
                time+=a[flag];
                per+=time;
                flag++;
                if(flag==n)
                {
                    printf("%d %d\n",flag,per);
                    break;
                }
            }
        }
    }
    return 0;
}
