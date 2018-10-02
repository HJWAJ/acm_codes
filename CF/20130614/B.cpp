#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
#include<sstream>
using namespace std;
char s[1000005];
int l[1000005],r[1000005];
int cnt1=0,cnt2=0;
int calc(int pos)
{
    if(l[pos]>r[cnt2-1])return 0;
    int ll=0,rr=cnt2,mid;
    while(ll<=rr)
    {
        mid=(ll+rr)/2;
        if(r[mid]>l[pos])rr=mid-1;
        else ll=mid+1;
    }
    if(r[ll-1]>l[pos])return cnt2-ll+1;
    if(r[ll]>l[pos])return cnt2-ll;
    if(r[mid]>l[pos])return cnt2-mid;
    if(r[mid+1]>l[pos])return cnt2-mid-1;
    return 0;
}
int main()
{
    int len,i;
    __int64 num=0;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<=len-5;i++)
        if(!strncmp(s+i,"heavy",5))
        {
            l[cnt1++]=i;
            //cout<<i<<' '<<endl;
        }
    //cout<<endl;
    for(i=0;i<=len-5;i++)
        if(!strncmp(s+i,"metal",5))
        {
            r[cnt2++]=i;
            //cout<<i<<' '<<endl;
        }
    //cout<<endl;
    //cout<<cnt1<<' '<<cnt2<<endl;
    for(i=0;i<cnt1;i++)
    {
        num+=calc(i);
        //cout<<num<<endl;
    }
    printf("%I64d\n",num);
    return 0;
}
