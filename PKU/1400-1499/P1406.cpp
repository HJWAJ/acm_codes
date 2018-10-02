#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<stack>
using namespace std;
bool bo[151205];
void init()
{
    int tmp,temp;
    for(int i=0;;i++)
    {
        tmp=i*i*i;
        if(tmp>151200)break;
        bo[tmp]=1;
        for(int j=0;;j++)
        {
            temp=tmp+j*(j+1)*(j+2)/6;
            if(temp>151200)break;
            bo[temp]=1;
        }
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n) && n)
    {
        while(!bo[n])n--;
        printf("%d\n",n);
    }
    return 0;
}
