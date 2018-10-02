#include<iostream>
using namespace std;

int main()
{
    int t,n,a[20],i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&a[0]);
        printf("1 ");
        for(i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>a[i-1])printf("1 ");
            else
            {
                for(j=i-1;j>=0;j--)
                {    
                    if(i-j<=a[i]-a[j])
                    {
                        printf("%d ",i-j);
                        break;
                    }
                    else if(j==0 && a[i]-a[0]<i)printf("%d ",i+1);
                }
            } 
        }
        printf("\n");      
    }    
    
    system("pause");
    return 0;
}
