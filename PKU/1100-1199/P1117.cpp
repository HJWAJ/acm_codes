#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int cmp(const void *p,const void *q)
{
    return *(int *)p - *(int *)q;
}
int getlen(int n)
{
    int res=0;
    if(n==0)return 1;
    while(n)
    {
        n/=10;
        res++;
    }
    return res;
}
int main()
{
    int n,i,j,len,ten[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000},a,b,c,nn,aa,bb,flag=0,ans[1005];
    int *p;
    scanf("%d",&n);
    len=getlen(n);
    if(n%11<10)
    {
        ans[flag]=n-n/11;
        flag++;
        //printf("%d + %d = %d\n",n-n/11,n/11,n);
    }
    for(i=1;i<len;i++)
    {
        nn=n;
        nn/=ten[i];
        a=nn/11;
        nn=n%ten[i];
        c=nn/2;
        for(b=0;b<=9;b++)
        {
            aa=a*ten[i]*10+b*ten[i]+c;
            bb=a*ten[i]+c;
            if(aa+bb==n)
            {
                ans[flag]=aa;
                flag++;
            }
        }
        if((n-ten[i])/ten[i])
        {
            c=(nn+ten[i])/2;
            for(b=0;b<=9;b++)
            {
                aa=a*ten[i]*10+b*ten[i]+c;
                bb=a*ten[i]+c;
                if(aa+bb==n)
                {
                    ans[flag]=aa;
                    flag++;
                }
            }
        }
    }
    qsort(ans,flag,sizeof(ans[0]),cmp);
    p=unique(ans,ans+flag);
    flag=p-ans;
    printf("%d\n",flag);
    for(i=0;i<flag;i++)
    {
        printf("%d + ",ans[i]);
        if(getlen(n-ans[i])<getlen(ans[i])-1)
            for(j=0;j<getlen(ans[i])-1-getlen(n-ans[i]);j++)printf("0");
        printf("%d = %d\n",n-ans[i],n);
    }
    return 0;
}
