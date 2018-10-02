#include<iostream>
#include<cstdio>
using namespace std;

int b[110][110],p[110][110];
int m[110];

int main()
{
    int n,minb,maxb,sump,minp;
    double max;
    int t; 
    scanf("%d",&t);
    while (t--)
    {
        maxb=0; minb=9999999;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m[i]);
            for(int j=0;j<m[i];j++)
            {
                scanf("%d %d",&b[i][j],&p[i][j]);
                if (maxb<b[i][j])maxb = b[i][j];
                if (minb>b[i][j])minb=b[i][j];
            }
        }
        max=0;
        for(int i=minb;i<=maxb;i++)
        {
            sump=0;
            for(int j=0;j<n;j++)
            {
                minp=999999;
                for(int k=0;k<m[j];k++)
                    if(b[j][k]>=i && p[j][k]<minp)minp=p[j][k];
                sump+=minp;
            }
            if((double)i/(double)sump>max)max=(double)i/(double)sump;
        }
        printf("%.3lf\n",max);
    }
    
    system("pause");
    return 0;
}
