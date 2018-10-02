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
bool chk(bool bo[],int n,int num)
{
    int i,cnt=0;
    for(i=0;i<n;i++)
        if(!bo[i])cnt++;
    if(cnt>=num)return 0;
    return 1;
}
int main()
{
    int a[105],b[105],n,k,q,i,num,tmp,g,sum,cnt,sum1,sum2;
    bool bo[105];
    memset(bo,0,sizeof(bo));
    double max=0,min=10000;
    scanf("%d%d",&n,&k);
    num=n/k;
    for(i=0;i<n;i++)scanf("%d",a+i);
    scanf("%d",&q);
    g=k-q;
    while(q--)
    {
        sum=0;
        for(i=0;i<num;i++)
        {
            scanf("%d",&tmp);
            sum+=a[tmp-1];
            bo[tmp-1]=1;
        }
        if(double(sum)/num>max)max=double(sum)/num;
        if(double(sum)/num<min)min=double(sum)/num;
    }
    if(chk(bo,n,num))printf("%.10lf %.10lf\n",min,max);
    else
    {
        sum=cnt=0;
        for(i=0;i<n;i++)
            if(!bo[i])
            {
                b[cnt]=a[i];
                cnt++;
            }
        sort(b,b+cnt);
        //for(i=0;i<cnt;i++)cout<<b[i]<<' ';
        //cout<<endl;
        sum1=sum2=0;
        for(i=0;i<num;i++)
        {
            sum1+=b[i];
            sum2+=b[cnt-1-i];
        }
        //cout<<num<<' '<<sum1<<' '<<sum2<<endl;
        if(double(sum2)/num>max)max=double(sum2)/num;
        if(double(sum1)/num<min)min=double(sum1)/num;
        printf("%.10lf %.10lf\n",min,max);
    }
	return 0;
}
