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
#include<ctime>
using namespace std;
int nums[105],nums2[105];
int prime[10000];
bool bo[10001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=100;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=10000;j+=i)bo[j]=1;
        }
    for(i=0;i<=10000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int len=0,a[105];
int two[105],len2=0,three[105],len3=0,eleven[105],len11=0;
int cnt[105];
int power(int a,int n)
{
    int res=1;
    for(int i=0;i<res;i++)
        res*=a;
    return res;
}
int div(int n,int a[],int numb[])
{
    memset(numb,0,sizeof(numb));
    int l=0,i=0,tmp;
    while(n>1)
    {
        if(n%prime[i]==0)
        {
            a[l++]=prime[i];
            tmp=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                tmp++;
            }
            numb[l-1]=tmp;
        }
        i++;
    }
    return l;
}
bool in(int num,int a[],int l)
{
    int i;
    for(i=0;i<l;i++)
        if(num==a[i])
            return 1;
    return 0;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    prime_table();
    int b,d,bo[4],i,flag,sum,max,flag3,flag11,gcdd,tmp3=0,tmp11=0,tt;
    memset(bo,0,sizeof(bo));
    scanf("%d%d",&b,&d);
    if((b-1)%d==0)
    {
        puts("3-type");
        return 0;
    }
    if((b+1)%d==0)
    {
        puts("11-type");
        return 0;
    }
    /*if(gcd(b+1,d)==b+1)
    {
        puts("11-type");
        return 0;
    }
    if(gcd(b-1,d)==b+1)
    {
        puts("3-type");
        return 0;
    }*/
    gcdd=gcd(b-1,d);
    if(gcdd!=1)
    {
        tmp3=1;
        d/=gcdd;
    }
    gcdd=gcd(b+1,b-1);
    tt=(b+1)/gcdd;
    gcdd=gcd(tt,d);
    if(gcdd!=1)
    {
        tmp11=1;
        d/=gcdd;
    }
    if(d==1)
    {
        if(tmp3 && tmp11)puts("6-type");
        else if(tmp3)puts("3-type");
        else if(tmp11)puts("11-type");
        return 0;
    }
    len2=div(b,two,nums2);
    len=div(d,a,nums);
    for(i=0;i<len;i++)
    {
        if(!in(a[i],two,len2))
            break;
    }
    if(i==len)
    {
        bo[0]=1;
        if(tmp3)bo[1]=1;
        if(tmp11)bo[2]=1;
        sum=bo[0]+bo[1]+bo[2];
        if(sum>1)puts("6-type");
        else
        {
            puts("2-type");
            memset(cnt,0,sizeof(cnt));
            for(i=0;i<len2;i++)
                while(d%two[i]==0)
                {
                    cnt[i]++;
                    d/=two[i];
                }
            max=0;
            for(i=0;i<len2;i++)
            {
                if(cnt[i]%nums2[i]==0)cnt[i]/=nums2[i];
                else cnt[i]=cnt[i]/nums2[i]+1;
                if(cnt[i]>max)max=cnt[i];
            }
            printf("%d\n",max);
        }
    }
    else puts("7-type");
    return 0;
}
