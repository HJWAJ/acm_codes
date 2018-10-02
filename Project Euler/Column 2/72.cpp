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
using namespace std;
/**
 *  ¼´eu(2)+...+eu(1000000)
 */
const int Max=1000001;
int eu[Max];
void euler()
{
	int i,j;
	for(i=2;i<Max;i++)
		if(!eu[i])
			for(j=i;j<Max;j+=i)
			{
				if(!eu[j])eu[j]=j;
				eu[j]=eu[j]/i*(i-1);
			}
}
int main()
{
    int i;
    long long sum=0;
    euler();
    for(i=2;i<Max;i++)sum+=eu[i];
    printf("%lld\n",sum);
    return 0;
}
