#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
bool favor[105];
struct movie
{
    char name[15];
    int num;
    int id[105];
    int maxval;
    int minval;
}mm[105];
bool check1(int i,int n)
{
    int j;
    for(j=0;j<n;j++)
        if(j!=i)
            if(mm[i].minval<mm[j].maxval)
                return 0;
    return 1;
}
bool check2(int i,int n)
{
    int j;
    for(j=0;j<n;j++)
        if(j!=i)
            if(mm[i].maxval<mm[j].minval)
                return 1;
    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,k,n,i,a,j,cnt,flag=0,tmp;
    memset(favor,0,sizeof(favor));
    scanf("%d%d",&m,&k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&a);
        favor[a]=1;
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cnt=0;
        scanf("%s",mm[i].name);
        scanf("%d",&mm[i].num);
        for(j=0;j<mm[i].num;j++)scanf("%d",&mm[i].id[j]);
        mm[i].minval=0;
        mm[i].maxval=0;
        for(j=0;j<mm[i].num;j++)
        {
            tmp=mm[i].id[j];
            if(!tmp)cnt++;
            else if(favor[tmp])
            {
                mm[i].minval++;
                mm[i].maxval++;
            }
        }
        //cout<<" "<<cnt<<" "<<mm[i].minval<<"mm"<<endl;
        if(cnt+mm[i].minval>k)mm[i].maxval=k;
        else mm[i].maxval+=cnt;
        if(cnt>m-k-(mm[i].num-cnt-mm[i].minval))mm[i].minval+=(cnt-(m-k-(mm[i].num-cnt-mm[i].minval)));
        //cout<<" "<<mm[i].maxval<<" "<<mm[i].minval<<endl;
    }
    //cout<<"ok"<<endl;
    for(i=0;i<n;i++)
    {
        if(check1(i,n))flag=0;
        else if(check2(i,n))flag=1;
        else flag=2;
        printf("%d\n",flag);
    }
    return 0;
}
