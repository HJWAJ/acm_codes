#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int i,ans=0;
    for(i=1;i<1000;i++)
        if(i%3==0 || i%5==0)ans+=i;
    printf("%d\n",ans);
    return 0;
}
