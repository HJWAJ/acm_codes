#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;
vector<int> v[105];
bool bo[105];
int dfs(int n)
{
    int num=v[n].size(),i,max=0,cnt;
    bo[n]=1;
    for(i=0;i<num;i++)
        if(!bo[v[n][i]])break;
    if(i==num)return 0;
    for(i=0;i<num;i++)
        if(!bo[v[n][i]])
        {
            cnt=dfs(v[n][i])+1;
            if(cnt>max)max=cnt;
        }
    return max;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t,sum=0,n,max,i,a,b,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)v[i].clear();
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            v[a-1].push_back(b-1);
            v[b-1].push_back(a-1);
        }
        max=0;
        for(i=0;i<n;i++)
        {
            memset(bo,0,sizeof(bo));
            cnt=dfs(i);
            //cout<<i<<' '<<cnt<<endl;
            if(cnt>max)max=cnt;
        }
        sum+=max;
    }
    printf("%d\n",sum);
	return 0;
}
