/*
ID: hjw00002
PROG: sort3
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int n,a[1005],i,j,k,cnt[2],num,flag1=0,flag2=0;
    cnt[0]=cnt[1]=cnt[2]=num=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
        if(a[i]==1)cnt[0]++;
        if(a[i]==2)cnt[1]++;
        if(a[i]==3)cnt[2]++;
    }
    //printf("%d %d %d\n",cnt[0],cnt[1],cnt[2]);
    for(i=0;i<cnt[0];i++)
    {
        if(a[i]==2)
        {
            for(j=cnt[0];j<cnt[0]+cnt[1];j++)
                if(a[j]==1)
                {
                    swap(a[i],a[j]);
                    //for(k=0;k<n;k++)printf("%d ",a[k]);printf("\n");
                    num++;break;
                }
            if(j==cnt[0]+cnt[1])
                for(;;j++)
                    if(a[j]==1)
                    {
                        swap(a[i],a[j]);
                        //for(k=0;k<n;k++)printf("%d ",a[k]);printf("\n");
                        num++;break;
                    }
        }
        if(a[i]==3)
        {
            for(j=cnt[0]+cnt[1];j<n;j++)
                if(a[j]==1)
                {
                    swap(a[i],a[j]);
                    //for(k=0;k<n;k++)printf("%d ",a[k]);printf("\n");
                    num++;break;
                }
            if(j==n)
                for(j=cnt[0];;j++)
                    if(a[j]==1)
                    {
                        swap(a[i],a[j]);
                        //for(k=0;k<n;k++)printf("%d ",a[k]);printf("\n");
                        num++;break;
                    }           
        }                     
    }
    for(i=cnt[0];i<cnt[0]+cnt[1];i++)
    {
        if(a[i]==3)
            for(j=cnt[0]+cnt[1];j<n;j++)
                if(a[j]==2)
                {
                    swap(a[i],a[j]);
                    //for(k=0;k<n;k++)printf("%d ",a[k]);printf("\n");
                    num++;break;
                }                                 
    }
    printf("%d\n",num);
    
    //system("pause");
    return 0;
}
