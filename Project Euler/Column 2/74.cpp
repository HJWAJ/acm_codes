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
#include<ctime>
#include<windows.h>
using namespace std;
int f[10]={1,1,2,6,24,120,720,5040,40320,362880};
int a[10000005];
set<int> s;
void calc(int n)
{
    int res=0,nn=n;
    while(n)
    {
        res+=f[n%10];
        n/=10;
    }
    a[nn]=res;
}
int main()
{
    int i,ans=0,tmp,tc,j;
    for(i=1;i<10000001;i++)calc(i);
    for(i=1;i<1000001;i++)
    {
        //system("pause");
        s.clear();
        j=i;
        tc=1;
        while(s.find(a[j])==s.end())
        {
            //cout<<j<<' ';
            s.insert(a[j]);
            j=a[j];
            tc++;
        }
        //cout<<j<<' '<<a[j]<<endl;
        //cout<<i<<' '<<tc<<endl;
        if(tc==60)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
