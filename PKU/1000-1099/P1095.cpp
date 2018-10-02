#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
void work(int n)
{
    int i,j,sum,m,a[19]={0,1,3,8,22,64,196,625,2055,6917,23713,82499,290511,1033411,3707851,13402696,48760366,178405156,656043856};
    if(n==0);
    else if(n==1)printf("X");
    else if(n==2)printf("X(X)");
    else if(n==3)printf("(X)X");
    else if(n==4)printf("X(X(X))");
    else if(n==5)printf("X((X)X)");
    else if(n==6)printf("(X)X(X)");
    else if(n==7)printf("(X(X))X");
    else if(n==8)printf("((X)X)X");
    else
    {
        for(i=2;i<19;i++)
            if(a[i]<n && a[i+1]>=n)
            {
                m=i+1;
                break;
            }
        if(n<=2*a[m-1]-a[m-2])
        {
            printf("X(");
            work(n-a[m-1]+a[m-2]);
            printf(")");                      
        }    
        else if(n>a[m]+a[m-2]-a[m-1] && n<=a[m])
        {
            printf("(");
            work(a[m-1]-a[m]+n);
            printf(")X");     
        }
        else
        {
            sum=2*a[m-1]-a[m-2];
            for(i=1;i<m;i++)
            {
                if(n>sum+(a[i]-a[i-1])*(a[m-1-i]-a[m-2-i]))sum+=(a[i]-a[i-1])*(a[m-1-i]-a[m-2-i]);
                else break;                
            }
            j=1;
            while(sum+j*(a[m-1-i]-a[m-2-i])<n)j++;
            printf("(");
            work(j+a[i-1]);
            printf(")X(");
            work(n-sum-(j-1)*(a[m-i-1]-a[m-i-2])+a[m-i-2]);
            printf(")");    
        }
    } 
    puts("");
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)work(n);
    return 0;
}
