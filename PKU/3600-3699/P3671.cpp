#include<iostream>
#include<cstdio>
using namespace std;

int s1[30002],s2[30002],c[30002];

int main()
{
    int i,j,N,min,temp;
    while(scanf("%d",&N)!=EOF)
    {
        s1[0]=0; 
        s2[0]=0;
        for(i=1;i<=N;i++)
        {
            scanf("%d",&c[i]);
            if(c[i]==1) 
            { 
                s1[i]=s1[i-1]+1; 
                s2[i]=s2[i-1]; 
            }
            else 
            { 
                s2[i]=s2[i-1]+1; 
                s1[i]=s1[i-1]; 
            }
        }
        min=100000;
        for(i=1;i<N;i++)
        {
             temp=s2[i]+s1[N]-s1[i];
             if(temp<min)
             min=temp;
        }
        if(min>s1[N])min=s1[N];
        if(min>s2[N])min=s2[N];
        printf("%d\n",min);
    }

    return 0;
}
