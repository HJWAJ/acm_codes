#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int prime[100005];
bool bo[1000005];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=1000000;i++)
        if(!bo[i])
        {
            prime[flag++]=i;
            j=i+i;
            for(;j<=1000000;j+=i)bo[j]=1;
        }
    return flag;
}
int divide(int n,int p[],int a[])
{
    int sq=(int)(sqrt(double(n)));
    int flag=0,num=0;
    while(1)
    {
        if(n==1)break;
        if(prime[flag]>sq)
        {
            p[num]=n;
            a[num++]=1;
            break;
        }
        if(n%prime[flag]!=0)
        {
            flag++;
            continue;
        }
        p[num]=prime[flag];
        a[num++]=1;
        n/=prime[flag];
        while(n%prime[flag]==0)
        {
            n/=prime[flag];
            a[num-1]++;
        }
        flag++;
    }
    return num;
}
int main()
{
    int flag=prime_table(),a,b,tt=0,p1[10005],p2[10005],a1[10005],a2[10005],num1,num2,cnt,dis,i,j;
    while(scanf("%d%d",&a,&b) && (a||b))
    {
        tt++;
        cnt=dis=0;
        num1=divide(a,p1,a1);
        num2=divide(b,p2,a2);
        i=j=0;
        while(i<num1 && j<num2)
        {
            while(p1[i]<p2[j])
            {
                cnt++;
                dis+=a1[i];
                i++;
                if(i==num1)break;
            }
            if(i==num1)break;
            while(p1[i]>p2[j])
            {
                cnt++;
                dis+=a2[j];
                j++;
                if(j==num2)break;
            }
            if(j==num2)break;
            if(p1[i]==p2[j])
            {
                cnt++;
                dis+=abs(a1[i]-a2[j]);
                i++;j++;
            }
        }
        while(i<num1)
        {
            cnt++;
            dis+=a1[i];
            i++;
        }
        while(j<num2)
        {
            cnt++;
            dis+=a2[j];
            j++;
        }
        printf("%d. %d:%d\n",tt,cnt,dis);
    }
    return 0;
}
