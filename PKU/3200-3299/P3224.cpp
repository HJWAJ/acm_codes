#include<iostream>
using namespace std;

int main()
{
    int cnt[100],n,num[100][100],i,j,max=0,maxnum;
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>num[i][j];
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
           if(num[i][j]==3)cnt[i]++;
           else cnt[j]++;
    for(i=0;i<n;i++)
        if(max<cnt[i]){max=cnt[i],maxnum=i;}
    printf("%d",maxnum+1);
    
    system("pause");
    return 0;
}
