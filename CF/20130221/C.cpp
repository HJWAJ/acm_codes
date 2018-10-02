#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<ctime>
#include<vector>
using namespace std;
const int mod=655373;
int a[100005];
vector<int> v[655373];
bool invec(int n)
{
    int rest=n%mod;
    for(int i=0;i<v[rest].size();i++)
        if(v[rest][i]==n)
            return 1;
    return 0;
}
int main()
{
    int n,k,i,ans=0;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",a+i);
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        if(a[i]%k==0 && !invec(a[i]/k))v[a[i]%mod].push_back(a[i]);
        else if(a[i]%k!=0)v[a[i]%mod].push_back(a[i]);
    }
    for(i=0;i<mod;i++)ans+=v[i].size();
    printf("%d\n",ans);
    return 0;
}
