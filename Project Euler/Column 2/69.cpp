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
int eu[1000005];
void euler()
{
	int i,j;
	for(i=2;i<1000001;i++)
		if(!eu[i])
			for(j=i;j<1000001;j+=i)
			{
				if(!eu[j])eu[j]=j;
				eu[j]=eu[j]/i*(i-1);
			}
}
int main()
{
    int num,i;
    double mmax=0;
    euler();
    for(i=2;i<1000001;i++)
        if(i*1.0/eu[i]>mmax)
        {
            mmax=i*1.0/eu[i];
            num=i;
        }
    printf("%d\n",num);
    return 0;
}
