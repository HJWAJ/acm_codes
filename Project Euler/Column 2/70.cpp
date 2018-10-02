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
int eu[10000005];
void euler()
{
	int i,j;
	for(i=2;i<10000001;i++)
		if(!eu[i])
			for(j=i;j<10000001;j+=i)
			{
				if(!eu[j])eu[j]=j;
				eu[j]=eu[j]/i*(i-1);
			}
}
bool check(int n)
{
    int a[10]={0},b[10]={0};
    int i,e=eu[n];
    i=0;
    while(n)
    {
        a[i++]=n%10;
        n/=10;
    }
    i=0;
    while(e)
    {
        b[i++]=e%10;
        e/=10;
    }
    sort(a,a+10);
    sort(b,b+10);
    for(i=0;i<10;i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}
int main()
{
    int num,i;
    double mmax=10000005;
    euler();
    for(i=2;i<10000001;i++)
        if(i*1.0/eu[i]<mmax && check(i))
        {
            mmax=i*1.0/eu[i];
            num=i;
        }
    printf("%d\n",num);
    return 0;
}
