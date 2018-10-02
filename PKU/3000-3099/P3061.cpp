#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[100005],b[100005];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,s,i,sum=0,flag1=0,flag2=0,res1,res2,min=999999,summ=0;
        scanf("%d%d",&n,&s);
        for(i=0;i<n;i++){scanf("%d",a+i);summ+=a[i];}
        if(summ<s){printf("0\n");continue;}
        while(flag2<n)
        {
            while(sum<s)
            {
                sum+=a[flag2];
                flag2++;
                if(flag2==n)break;
            }
            while(sum>=s)
            {
                sum-=a[flag1];
                flag1++;             
            }
            if(flag2-flag1<min)min=flag2-flag1;   
        }
        printf("%d\n",min+1);
    }    
    
    system("pause");
    return 0;
}
