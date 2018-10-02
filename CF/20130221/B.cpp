#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<ctime>
using namespace std;
int n,m;
char s[55][55];
int main()
{
    int i,j,x1,y1,x2,y2,flag=1,k,tmp;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)scanf("%s",s[i]);
    for(i=0;i<n*m;i++)
        for(j=i+1;j<n*m;j++)
        {
            tmp=1;
            x1=i/n;
            y1=i%n;
            x2=j/n;
            y2=j%n;
            if(s[x1][y1]=='W' || s[x2][y2]=='W')continue;
            if(x1>x2)
            {
                for(k=x2+1;k<x1;k++)
                    if(s[k][y1]=='W')
                        tmp=0;
                if(tmp)
                {
                    if(y1>y2)
                    {
                        for(k=y2+1;k<y1;k++)
                            if(s[x2][k]=='W')
                                tmp=0;
                    }
                    else if(y1<y2)
                    {
                        for(k=y1+1;k<y2;k++)
                            if(s[x2][k]=='W')
                                tmp=0;
                    }
                }
                if(tmp)continue;
                tmp=1;
                if(y1>y2)
                {
                    for(k=y2+1;k<y1;k++)
                        if(s[x1][k]=='W')
                            tmp=0;
                }
                else if(y1<y2)
                {
                    for(k=y1+1;k<y2;k++)
                        if(s[x1][k]=='W')
                            tmp=0;
                }
                if(tmp)
                {
                    for(k=x2+1;k<x1;k++)
                        if(s[k][y2]=='W')
                            tmp=0;
                }
                if(tmp==0)flag=0;
            }
            else if(x1==x2)
            {
                if(y1>y2)
                {
                    for(k=y2+1;k<y1;k++)
                        if(s[x2][k]=='W')
                            tmp=0;
                }
                else if(y1<y2)
                {
                    for(k=y1+1;k<y2;k++)
                        if(s[x2][k]=='W')
                            tmp=0;
                }
                if(tmp==0)flag=0;
            }
            else
            {
                for(k=x1+1;k<x2;k++)
                    if(s[k][y1]=='W')
                        tmp=0;
                if(tmp)
                {
                    if(y1>y2)
                    {
                        for(k=y2+1;k<y1;k++)
                            if(s[x2][k]=='W')
                                tmp=0;
                    }
                    else if(y1<y2)
                    {
                        for(k=y1+1;k<y2;k++)
                            if(s[x2][k]=='W')
                                tmp=0;
                    }
                }
                if(tmp)continue;
                tmp=1;
                if(y1>y2)
                {
                    for(k=y2+1;k<y1;k++)
                        if(s[x1][k]=='W')
                            tmp=0;
                }
                else if(y1<y2)
                {
                    for(k=y1+1;k<y2;k++)
                        if(s[x1][k]=='W')
                            tmp=0;
                }
                if(tmp)
                {
                    for(k=x1+1;k<x2;k++)
                        if(s[k][y2]=='W')
                            tmp=0;
                }
                if(tmp==0)flag=0;
            }
        }
    if(flag)puts("YES");
    else puts("NO");
    return 0;
}
