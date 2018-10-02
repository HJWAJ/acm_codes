//估计最大满足条件的不会太大，实际上最大的是194979。在没有正规思路时要有靠谱的蒙的想法和方法。——上海赛区教训！ 
/*
正解：对于每一位来说，最大值是9^5=59049，也就是说，满足的len，使len*59049有可能>n，可以确定一个n的范围。 
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
long long a[15],len;
long long getnum(long long n)
{
    int i=0;
    while(n)
    {
        a[i++]=n%10;
        n/=10;
    }
    return i;
}
long long pow(long long len)
{
    long long i,sum=0;
    for(i=0;i<len;i++)sum+=a[i]*a[i]*a[i]*a[i]*a[i];
    return sum;
}
int main()
{
    long long sum=0,tmp,i;
    for(i=2;i<10000000LL;i++)
    {
        len=getnum(i);
        if(pow(len)==i)
        {
            cout<<i<<endl;
            sum+=i;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
