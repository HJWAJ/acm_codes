#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool finish(int a[1000],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]<k)return 1;
    return 0;     
}

int main()
{
    int a[1000],n,k,i,tmp,cnt=0;
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%d",a+i);
    while(finish(a,n,k))
    {
        tmp=a[0];
        for(i=0;i<n+1;i++)
        {
            if(a[i]!=tmp)
            {
                a[i-1]++;
                tmp=a[i];
            }
            if(a[i]>=k)break;
        }
        //for(i=0;i<n;i++)printf("%d ",a[i]);
        cnt++;
    }
    printf("%d\n",cnt);    
    //system("pause");
    return 0;
}
