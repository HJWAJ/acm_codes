//母函数，毫不节省内存的写法，其实可以滚动数组优化 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
int a[8]={1,2,5,10,20,50,100,200};
int num[8][205],len[8];
int ans[8][1405];
int main()
{
    int i,j,k;
    memset(num,0,sizeof(num));
    memset(ans,0,sizeof(ans));
    for(i=0;i<8;i++)
    {
        len[i]=0;
        while(a[i]*len[i]<=200)
        {
            num[i][len[i]]=a[i]*len[i];
            len[i]++;
        }
    }
    for(i=0;i<=200;i++)ans[0][i]=1;
    for(i=1;i<8;i++)
        for(j=0;j<=1200;j++)
            for(k=0;k<len[i];k++)
                ans[i][j+num[i][k]]+=ans[i-1][j];
    printf("%d\n",ans[7][200]);
    return 0;
}
