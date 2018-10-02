#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cmath>
#include<string>
using namespace std;
int prime[200000];
bool bo[1000001];
int cnt[1000001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=1000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=1000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=1000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
bool calc(int a,int b,int len,int k)
{
    for(int i=a;i<=b-len+1;i++)
        if(cnt[i+len-1]-cnt[i-1]<k)
            return 0;
    return 1;
}
int main()
{
    int a,b,k,l,r,mid,i;
    bool bo1,bo2;
    prime_table();
    cnt[0]=0;
    for(i=1;i<=1000000;i++)
    {
        if(!bo[i])cnt[i]=cnt[i-1]+1;
        else cnt[i]=cnt[i-1];
    }
    //for(i=0;i<=10;i++)cout<<cnt[i]<<' ';
    //cout<<endl;
    scanf("%d%d%d",&a,&b,&k);
    l=1;
    r=b-a+1;
    if(calc(a,b,l,k))puts("1");
    else if(!calc(a,b,r,k))puts("-1");
    else
    {
        while(l<r)
        {
            mid=(l+r)/2;
            bo1=calc(a,b,mid,k);
            bo2=calc(a,b,mid-1,k);
            if(bo1 && bo2)r=mid-1;
            else if(!bo1 && !bo2)l=mid+1;
            else if(bo1 && !bo2)
            {
                printf("%d\n",mid);
                goto done;
            }
        }
        if(calc(a,b,l,k) && !calc(a,b,l-1,k))printf("%d\n",l);
        else if(!calc(a,b,l,k) && calc(a,b,l+1,k))printf("%d\n",l+1);
    }
    done:;
    return 0;
}
