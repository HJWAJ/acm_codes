#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
using namespace std;
int sushu[50000];
bool dabiao[100001];
int sushubiao()//+++++——
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j,flag=0;
    for(i=2;i<=100000;i++)
        if(dabiao[i]==0)
        {
            sushu[flag++]=i;
            for(j=2;j<=100000/i;j++)dabiao[j*i]=1;
        }
    return flag;
}
int main()
{
    int flag=sushubiao();
    int m,a,b,i,j,max,p,q,t,mm;
    while(scanf("%d%d%d",&m,&a,&b) && (m||a||b))
    {
        mm=int(sqrt(double(m)));
        for(i=0;i<flag;i++)
            if(sushu[i]>=m)break;
        t=i;
        i=max=0;
        while(i<t)
        {
            if(sushu[i]>mm)break;
            j=i;
            while(j<t)
            {
                if(sushu[i]*sushu[j]>m)break;
                if(sushu[j]*a>sushu[i]*b)break;
                if(sushu[i]*sushu[j]>max)
                {
                    p=sushu[i];
                    q=sushu[j];
                    max=sushu[i]*sushu[j];
                }
                j++;
            }
            i++;
        }
        printf("%d %d\n",p,q);
    }
    return 0;
}
