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
using namespace std;
const int hashmax=655373;
bool hashtable[hashmax];
int data[hashmax], maps[hashmax];
unsigned int hash(unsigned int a)
{
    return (a^0xA5A5A5A5)%hashmax;
}
void add(int aj,int j)
{
    int idx=hash(aj);
    while(hashtable[idx])
    {
        idx++;
        if(idx==hashmax)idx-=hashmax;
    }
    hashtable[idx]=1;
    data[idx]=aj;
    maps[idx]=j;
}
int query(int aj)
{
    int idx=hash(aj);
    while(hashtable[idx])
    {
        if(data[idx]==aj)return maps[idx];
        idx++;
        if(idx==hashmax)idx-=hashmax;
    }
    return -1;
}
pair<int,int> euclid(int a,int b)
{
    if(b==0)return make_pair(1,0);
    else
    {
        pair<int,int> ans=euclid(b,a%b);
        return make_pair(ans.second, ans.first - ans.second*(a/b));
    }
}
int main()
{
    int p,b,n,aj,opp,t,ans;
    while(scanf("%d%d%d",&p,&b,&n)!=EOF)
    {
        int m=(int)ceil(sqrt((double)p));
        memset(hashtable,0,sizeof(hashtable));
        aj=1;
        for(int j=0;j<m;j++)
        {
            add(aj,j);
            aj=(long long)aj * b % p;
        }
        opp= (euclid(aj,p).first % p + p) % p;
        aj=n;
        ans=-1;
        for(int i=0;i<m;i++)
        {
            t=query(aj);
            if(t!=-1)
            {
                ans=i*m+t;
                break;
            }
            aj=(long long)aj * opp % p;
        }
        if(ans==-1)printf("no solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}
