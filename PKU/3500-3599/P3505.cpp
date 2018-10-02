#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int h,l,a[50][50],x[2500],y[2500],max=0,sum=0;
        scanf("%d%d",&h,&l);
        int i,j;
        for(i=h-1;i>=0;i--)
            for(j=0;j<l;j++)
            {    
                scanf("%d",&a[i][j]);
                if(a[i][j]!=-1)
                {
                    x[a[i][j]-1]=i;
                    y[a[i][j]-1]=j;
                    if(max<a[i][j])max=a[i][j];
                }
            }
        int xx=0,yy=0;
        for(i=0;i<max;i++)
        {
            //printf("%d %d\n",x[i],y[i]);
            sum=sum+10*abs(xx-x[i]);
            xx=x[i];
            if(abs(yy-y[i])<=abs(yy-(y[i]-l)))sum=sum+5*abs(yy-y[i]);
            else sum=sum+5*abs(yy-(y[i]-l));
            yy=y[i];                  
        }
        printf("%d\n",sum);
    }    
    
    system("pause");
    return 0;
}
