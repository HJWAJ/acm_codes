#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
int prime[4000];
bool bo[40001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=200;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=40000;j+=i)bo[j]=1;
        }
    for(i=0;i<=40000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
bool check(int aa,int b)
{
    int a[2][4];
    a[0][0]=aa/1000;a[0][1]=aa/100%10;a[0][2]=aa/10%10;a[0][3]=aa%10;
    a[1][0]=b/1000;a[1][1]=b/100%10;a[1][2]=b/10%10;a[1][3]=b%10;
    sort(a[0],a[0]+4);
    sort(a[1],a[1]+4);
    for(int i=0;i<4;i++)
        if(a[0][i]!=a[1][i])return 0;
    return 1;
}
int main()
{
    int i,a[4],cnt,val,tmp,d;
    prime_table();
    for(i=0;prime[i]<1000;i++);
    for(;prime[i]<10000;i++)
    {
        tmp=prime[i];
        a[0]=tmp/1000;
        a[1]=tmp/100%10;
        a[2]=tmp/10%10;
        a[3]=tmp%10;
        cnt=0;
        do
        {
            next_permutation(a,a+4);
            val=a[0]*1000+a[1]*100+a[2]*10+a[3];
            if(!bo[val] && a[0])
            {
                d=val-tmp;
                if(!bo[val+d] && check(val,val+d) && d)
                {
                    printf("%d %d %d\n",tmp,val,val+d);
                    break;
                }
            }
        }while(val>prime[i]);
    }
    return 0;
}
