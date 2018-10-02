#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<map>
using namespace std;
map<int,int> mymap;
int kind[10005],num;
struct node
{
    int ans[4],size,maxkind,maxval;
};
vector<node> v;
bool cmp(int a,int b)
{
    return a>b;
}
bool cmp1(node a,node b)
{
    if(a.maxkind!=b.maxkind)return a.maxkind > b.maxkind;
    if(a.size!=b.size)return a.size<b.size;
    if(a.maxval!=b.maxval)return a.maxval > b.maxval;
}
int main()
{
    int a,i,j,ii,jj;
    node nd;
    while(scanf("%d",&a)!=EOF)
    {
        mymap.clear();
        num=0;
        if(a==0)
        {
            while(scanf("%d",&a) && a)
            {
                printf("%d ---- none\n",a);
            }
        }
        else
        {
            if(mymap[a]<=4)
            {
                mymap[a]++;
                kind[num++]=a;
            }
            while(scanf("%d",&a) && a)
            {
                if(mymap[a]>4)continue;
                else
                {
                    mymap[a]++;
                    kind[num++]=a;
                }
            }
            sort(kind,kind+num,cmp);
            while(scanf("%d",&a) && a)
            {
                v.clear();
                for(i=0;i<num;i++)
                {
                    if(kind[i]>a)continue;
                    if(kind[i]==a)
                    {
                        //cout<<kind[i]<<endl;
                        nd.ans[0]=kind[i];
                        nd.maxkind=1;
                        nd.maxval=kind[i];
                        nd.size=1;
                        v.push_back(nd);
                        continue;
                    }
                    for(j=i;j<num;j++)
                    {
                        if(kind[i]+kind[j]>a)continue;
                        if(kind[i]+kind[j]==a)
                        {
                            //cout<<kind[i]<<' '<<kind[j]<<endl;
                            nd.ans[0]=kind[i];
                            nd.ans[1]=kind[j];
                            nd.maxkind=2;
                            if(i==j)nd.maxkind--;
                            nd.maxval=kind[i];
                            nd.size=2;
                            v.push_back(nd);
                            continue;
                        }
                        for(ii=j;ii<num;ii++)
                        {
                            if(kind[i]+kind[j]+kind[ii]>a)continue;
                            if(kind[i]+kind[j]+kind[ii]==a)
                            {
                                //cout<<kind[i]<<' '<<kind[j]<<' '<<kind[ii]<<endl;
                                nd.ans[0]=kind[i];
                                nd.ans[1]=kind[j];
                                nd.ans[2]=kind[ii];
                                nd.maxkind=3;
                                if(i==j)nd.maxkind--;
                                if(ii==j)nd.maxkind--;
                                nd.maxval=kind[i];
                                nd.size=3;
                                v.push_back(nd);
                                continue;
                            }
                            for(jj=ii;jj<num;jj++)
                            {
                                if(kind[i]+kind[j]+kind[ii]+kind[jj]>a)continue;
                                if(kind[i]+kind[j]+kind[ii]+kind[jj]==a)
                                {
                                    //cout<<kind[i]<<' '<<kind[j]<<' '<<kind[ii]<<' '<<kind[jj]<<endl;
                                    nd.ans[0]=kind[i];
                                    nd.ans[1]=kind[j];
                                    nd.ans[2]=kind[ii];
                                    nd.ans[3]=kind[jj];
                                    nd.maxkind=4;
                                    if(i==j)nd.maxkind--;
                                    if(ii==j)nd.maxkind--;
                                    if(ii==jj)nd.maxkind--;
                                    nd.maxval=kind[i];
                                    nd.size=4;
                                    v.push_back(nd);
                                    continue;
                                }
                            }
                        }
                    }
                }
                sort(v.begin(),v.end(),cmp1);
                if(v.size()==0)printf("%d ---- none\n",a);
                else
                {
                    if(v.size()==1 || v[0].maxkind!=v[1].maxkind || v[0].size!=v[1].size || v[0].maxval!=v[1].maxval)
                    {
                        printf("%d (%d):",a,v[0].maxkind);
                        sort(v[0].ans,v[0].ans+v[0].size);
                        for(i=0;i<v[0].size;i++)printf(" %d",v[0].ans[i]);
                        puts("");
                    }
                    else
                    {
                        printf("%d (%d): tie\n",a,v[0].maxkind);
                    }
                }
            }
        }
    }
    return 0;
}
