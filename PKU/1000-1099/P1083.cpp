#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,n,a,b,cnt[205],i,max;
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        max=0;
        while(n--)      
        {
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            for(i=(a-1)/2;i<=(b-1)/2;i++)cnt[i]++;                
        }
        for(i=0;i<200;i++)
            if(max<cnt[i])max=cnt[i];
        printf("%d\n",max*10);
    }    
    
    system("pause");
    return 0;
}
