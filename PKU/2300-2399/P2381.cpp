#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

bool val[16000001];
int r[10000000];

int main()
{
    long long int a,c,m,max=0,sub,i=0,num;
    scanf("%lld%lld%lld%lld",&a,&c,&m,r);
    memset(val,0,sizeof(val));
    do
    {
        val[r[i]]=1;
        i++;
        r[i]=(a*r[i-1]+c)%m;
    }while(val[r[i]]==0);
    sort(r,r+i);
    num=i;
    for(i=0;i<num-1;i++)
    {
        sub=abs(r[i+1]-r[i]);
        if(max<sub)max=sub;
    }
    printf("%d\n",max);
    
    system("pause");
    return 0;
}
