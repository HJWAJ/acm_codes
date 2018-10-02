#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
const double eps=1e-8;
int prime[200000];
bool bo[1000001];
int prime_table()
{
    int i,j,flag=0;
    memset(bo,0,sizeof(bo));
    bo[0]=bo[1]=1;
    for(i=2;i<=1000;i++)
        if(!bo[i])
        {
            j=i*i;
            for(;j<=1000000;j+=i)bo[j]=1;
        }
    for(i=0;i<=1000000;i++)
        if(!bo[i])prime[flag++]=i;
    return flag;
}
int main()
{
    prime_table();
    int n;
    __int64 a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%I64d",&a);
        __int64 sq=(__int64)sqrt((long double)a);
        //cout<<sq<<endl;
        if(fabs(sq*sq-a)<eps && !bo[(int)sq])puts("YES");
        else puts("NO");
    }
    return 0;
}
