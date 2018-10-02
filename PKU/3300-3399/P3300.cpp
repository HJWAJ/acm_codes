#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

double r[12],f[12],s[102];

int main()
{
    int i,j,k,R,F;
    double d,ans;
    while(scanf("%d",&F) && F)
    {
        if(F==0)break;
        scanf("%d",&R);
        for(i=0;i<F;i++)scanf("%lf",&f[i]);
        for(i=0;i<R;i++)scanf("%lf",&r[i]);
        for(i=0,k=0;i<F;i++)
            for(j=0;j<R;j++)
            {
                d=r[j]/f[i];
                s[k++]=d;
            }
        sort(s,s+k);
        ans=0.0;
        for(i=1;i<k;i++)
        {
            d=s[i]/s[i-1];
            if(d>ans)ans=d;
        }
        printf("%.2lf\n",ans);
    }
    
    //system("pause");
    return 0;
}

