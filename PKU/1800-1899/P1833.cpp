#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,k,m,a[2000];
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&n,&k);
        for(int j=0;j<n;j++)
            scanf("%d",a+j);
        for(int j=0;j<k;j++) 
        {
            next_permutation(a,a+n);
        }
        for (int j=0;j<n;j++)
        {
            if(j!=n-1)printf("%d ",a[j]);
            else printf("%d\n",a[j]);
        }
    }
    system("pause");
    return 0;
}
