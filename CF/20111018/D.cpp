#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;
int can(int a,int b,int c,int aa,int bb,int cc)
{
    if(a==aa && b==bb && c==cc)return 1;
    if(a==aa && b==cc && c==bb)return 1;
    if(a==bb && b==aa && c==cc)return 1;
    if(a==bb && b==cc && c==aa)return 1;
    if(a==cc && b==aa && c==bb)return 1;
    if(a==cc && b==bb && c==aa)return 1;
    return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,a[55][55],i,j,sum,cnt=0;
    int row[55],col[55];
    int A,B,C;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    scanf("%d%d%d",&A,&B,&C);
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    sum=0;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            sum+=a[i][j];
            row[i]+=a[i][j];
            col[j]+=a[i][j];
        }
    for(i=1;i<m;i++)row[i]+=row[i-1];
    for(i=1;i<n;i++)col[i]+=col[i-1];
    if(sum!=A+B+C)
    {
        puts("0");
        return 0;
    }

    for(i=0;i<m-2;i++)
        for(j=i+1;j<m-1;j++)
            if(can(A,B,C,row[i],row[j]-row[i],row[m-1]-row[j]))cnt++;

    for(i=0;i<n-2;i++)
        for(j=i+1;j<n-1;j++)
            if(can(A,B,C,col[i],col[j]-col[i],col[n-1]-col[j]))cnt++;

    printf("%d\n",cnt);
	return 0;
}
