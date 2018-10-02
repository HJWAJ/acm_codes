#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t,i,j,a[10000],cnt,sum;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        cnt=0;
        sum=0;
        for(j=0;j<m;j++)scanf("%d",&a[j]);
        sort(a,a+m);
        for(j=m-1;j>=0;j--){sum+=a[j];cnt++;if(sum>=n)break;}
        printf("Scenario #%d:\n",i+1);
        if(j!=-1)printf("%d\n\n",cnt);
        else printf("impossible\n\n");
    }    
    
    system("pause");
    return 0;
}
