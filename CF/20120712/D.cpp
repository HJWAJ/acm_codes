#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
map<int,int> m1,m2;
int main()
{
    int n,i,a,b,min=(1<<24),half,tmp;
    scanf("%d",&n);
    half=(n+1)/2;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        m1[a]++;
        if(a!=b)m2[b]++;
    }
    for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++)
    {
        if(m1[it->first]>=half)
        {
            puts("0");
            return 0;
        }
        else if(m1[it->first]+m2[it->first]>=half)
        {
            tmp=half-m1[it->first];
            if(tmp<min)min=tmp;
        }
    }
    for(map<int,int>::iterator it=m2.begin();it!=m2.end();it++)
    {
        if(m1[it->first]+m2[it->first]>=half && m1[it->first]==0)
        {
            tmp=half;
            if(tmp<min)min=tmp;
        }
    }
    if(min==(1<<24))puts("-1");
    else printf("%d\n",min);
    return 0;
}
