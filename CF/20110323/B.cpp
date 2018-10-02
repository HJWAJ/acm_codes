#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int i,j,n,m,l[105],r[105],t[105],c[105],sum,min,minc;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)scanf("%d%d%d%d",l+i,r+i,t+i,c+i);
    min=sum=0;                
    for(i=1;i<=n;i++)
    {
        min=99999999;
        for(j=0;j<m;j++)
        {
            if(l[j]<=i && r[j]>=i)
                if(min>t[j])
                {
                    min=t[j];
                    minc=c[j];
                }
        }
        if(min!=99999999)sum+=minc;                
    }
    printf("%d\n",sum);
    
    //system("pause");
    return 0;
}
