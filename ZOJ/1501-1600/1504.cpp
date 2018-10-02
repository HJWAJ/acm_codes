#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
bool bo[26];
char s[15][15];
const double sq3=sqrt(3.0);
const double eps=1e-8;
bool check(int i,int j,int ii,int jj,int k,int kk,int n)
{
    if(s[i][j]!=s[ii][jj] || s[ii][jj]!=s[k][kk] || s[i][j]!=s[k][kk])return 0;
    if((i==ii && j==jj) || (i==k && j==kk) || (ii==k && jj==kk))return 0;
    double x1,x2,x3,y1,y2,y3;
    x1=n-i+2*j;
    x2=n-ii+2*jj;
    x3=n-k+2*kk;
    y1=1+sq3*(n-i-1);
    y2=1+sq3*(n-ii-1);
    y3=1+sq3*(n-k-1);
    //cout<<i<<' '<<j<<' '<<ii<<' '<<jj<<' '<<k<<' '<<kk<<endl;
    //cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<x3<<' '<<y3<<endl;
    //cout<<(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<<' '<<(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)<<' '<<(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)<<endl;
    if(fabs(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) - ((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)))<eps
    && fabs(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) - ((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)))<eps)return 1;
    else return 0;
}
int main()
{
    int n,i,j,flag,ii,jj,k,kk;
    while(scanf("%d",&n) && n)
    {
        getchar();
        flag=0;
        memset(s,0,sizeof(s));
        memset(bo,0,sizeof(bo));
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
                scanf("%c",&s[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
                for(ii=0;ii<n;ii++)
                    for(jj=0;jj<=i;jj++)
                        for(k=0;k<n;k++)
                            for(kk=0;kk<=k;kk++)
                                if(check(i,j,ii,jj,k,kk,n))
                                {
                                    //cout<<s[i][j]<<endl;
                                    bo[s[i][j]-'a']=1;
                                    flag=1;
                                }
        //for(i=0;i<26;i++)cout<<bo[i]<<' ';
        //cout<<endl;
        if(!flag)puts("LOOOOOOOOSER!");
        else
        {
            for(i=0;i<26;i++)
                if(bo[i])
                    printf("%c",i+'a');
            puts("");
        }
    }
    return 0;
}
