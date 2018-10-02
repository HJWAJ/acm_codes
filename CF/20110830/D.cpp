#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
int num[1000005],cnt=1;
__int64 str2int(char s[],__int64 len)
{
    long long i,res=0;
    for(i=0;i<len;i++)
    {
        res*=10;
        res+=(s[i]-'0');
    }
    return res;
}
void getnum()
{
    num[0]=0;
    char s[10];
    __int64 i,j,k,tmp,ini;
    for(i=1;i<=9;i++)
        for(j=i;j>=0;j--)
        {
            for(k=0;k<j;k++)s[k]='4';
            for(;k<i;k++)s[k]='7';
            tmp=str2int(s,i);
            ini=tmp;
            num[cnt++]=ini;
            do
            {
                next_permutation(s,s+i);
                tmp=str2int(s,i);
                if(tmp>ini)num[cnt++]=tmp;
                else break;
            }while(1);
        }
    num[cnt]=9999999999;
}
__int64 getsection(__int64 a,__int64 b,__int64 c,__int64 d)
{
    if(c<=a && d>=b)return b-a+1;
    if(c<=a && d>=a)return d-a+1;
    if(c>=a && d<=b)return d-c+1;
    if(d>=b && c<=b)return b-c+1;
    return 0;
}
int main()
{
    getnum();
    __int64 pl,pr,vl,vr,k,i,fenzi=0,fenmu;
    double p;
    scanf("%I64d%I64d%I64d%I64d%I64d",&pl,&pr,&vl,&vr,&k);
    //for(i=0;i<=cnt;i++)cout<<num[i]<<' ';
    //cout<<endl;
    sort(num,num+cnt+1);
    for(i=1;i<=cnt-k;i++)
    {
        fenzi+=getsection(num[i-1]+1,num[i],pl,pr) * getsection(num[i+k-1],num[i+k]-1,vl,vr);
        fenzi+=getsection(num[i-1]+1,num[i],vl,vr) * getsection(num[i+k-1],num[i+k]-1,pl,pr);
    }
    fenmu=(pr-pl+1) * (vr-vl+1);
    if(k==1)
        for(i=0;i<cnt;i++)
            if(num[i]>=pl && num[i]>=vl && num[i]<=pr && num[i]<=vr)
                fenzi--;
    //cout<<fenzi<<' '<<fenmu<<endl;
    p=(double)fenzi/fenmu;
    printf("%.10lf\n",p);
	return 0;
}
