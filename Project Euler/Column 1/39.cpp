#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
int main()
{
    int i,j,k,p,max=-1,maxp,cnt;
    for(p=1;p<1001;p++)
    {
        cnt=0;
        for(i=1;i<p;i++)
            for(j=i+1;j<p;j++)
            {
                k=p-i-j;
                if(k>0 && i*i+j*j==k*k)cnt++;
            }
        if(cnt>max)
        {
            max=cnt;
            maxp=p;
        }
    }
    printf("%d\n",maxp);
    return 0;
}
