#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int main()
{
    int a,b,s=2000000,s1,s2,min=2000000,tmp1,tmp2,ans,tmp;
    for(a=1;a*(a+1)/2<=s;a++)
    {
        tmp=a*(a+1)/2;
        for(b=1;b*(b+1)/2*tmp<=s;b++)s1=b*(b+1)/2*tmp;
        s2=b*(b+1)/2*tmp;
        tmp1=abs(s-s1);
        tmp2=abs(s2-s);
        if(tmp1<min)
        {
            min=tmp1;
            ans=a*(b-1);
        }
        if(tmp2<min)
        {
            min=tmp2;
            ans=a*b;
        }
    }
    printf("%d\n",ans);
    return 0;
}
