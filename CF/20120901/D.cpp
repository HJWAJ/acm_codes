#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int cnt;
    vector<int> v;
};
map<int,node> mymap;
map<int,node>::iterator it;
int ok1[1005],ok2[1005];
int main()
{
    node nd;
    int n,a,nn=0,num1=0,q,ll,rr,ct,i,num2=0,j,l1,r1;
    vector<int> v;
    scanf("%d%d",&n,&q);
    while(n--)
    {
        nn++;
        scanf("%d",&a);
        it=mymap.find(a);
        if(it!=mymap.end())
        {
            mymap[a].cnt++;
            mymap[a].v.push_back(nn);
        }
        else
        {
            nd.cnt=1;
            nd.v.clear();
            nd.v.push_back(nn);
            mymap[a]=nd;
        }
    }
    for(it=mymap.begin();it!=mymap.end();it++)
    {
        if(it->first==(it->second).cnt)ok1[num1++]=it->first;
        if(it->first<(it->second).cnt)ok2[num2++]=it->first;
    }
    while(q--)
    {
        ct=0;
        scanf("%d%d",&ll,&rr);
        for(i=0;i<num1;i++)
            if(mymap[ok1[i]].v[0]>=ll && mymap[ok1[i]].v[mymap[ok1[i]].v.size()-1]<=rr)
            {
                //cout<<"ok"<<' '<<ok1[i]<<' '<<mymap[ok1[i]].v[0]<<' '<<mymap[ok1[i]].v[mymap[ok1[i]].v.size()-1]<<endl;
                ct++;
            }
        for(i=0;i<num2;i++)
        {
            v=mymap[ok2[i]].v;
            //for(j=0;j<v.size();j++)cout<<v[j]<<' ';
            //cout<<endl;
            for(j=0;j<v.size();j++)
                if(v[j]>=ll)
                    break;
            if(j==v.size())continue;
            l1=j;
            for(j=v.size()-1;j>=0;j--)
                if(v[j]<=rr)
                    break;
            if(j==-1)continue;
            r1=j;
            //cout<<l1<<' '<<r1<<endl;
            if(r1-l1+1==ok2[i])ct++;
        }
        printf("%d\n",ct);
    }
    return 0;
}
