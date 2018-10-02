#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define esp 1e-10
using namespace std;
const int Max=1000001;
long long int eu[Max];
void eular()
{
	long long int i,j;
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
    eular();
    long long int ans,i,j,k;
    while(scanf("%lld%lld",&i,&j)!=EOF)
    {
        ans=1;
        for(k=i;k<=j;k++)
        {
            ans*=eu[k];
            ans%=99991;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
