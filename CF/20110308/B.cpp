#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,a[1005],num,i,j,max;
    while(scanf("%d",&n)!=EOF)
    {
        max=0;
        for(i=0;i<n;i++)scanf("%d",a+i);
        for(i=0;i<n;i++)
        {
            num=1;
            for(j=i-1;j>=0;j--)
            {
                if(a[j+1]>=a[j])num++;
                else break;
            }
            for(j=i+1;j<n;j++)
            {
                if(a[j]<=a[j-1])num++;
                else break;
            }
            if(max<num)max=num;
            //printf("%d ",num);                
        }
        //printf("\n");
        printf("%d\n",max);                          
    }
    
    return 0;
}
