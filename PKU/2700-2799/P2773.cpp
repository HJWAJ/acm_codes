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
const int Max=1000001;
int eu[Max];
void euler()
{
	int i,j;
	eu[1]=1;
	for(i=2;i<Max;i++)
		if(!eu[i])
			for(j=i;j<Max;j+=i)
			{
				if(!eu[j])eu[j]=j;
				eu[j]=eu[j]/i*(i-1);
			}
}

long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    long long i,m,cnt;
    int k,len;
    euler();
    while(scanf("%lld%d",&m,&k)!=EOF)
    {
        tt++;
        len=0;
        cnt=k/eu[(int)m];
        k%=eu[(int)m];
        if(k==0)
        {
            k=eu[(int)m];
            cnt--;
        }
        for(i=1;i<=m&&len<k;i++)
            if(gcd(i,m)==1)
                len++;
        printf("%lld\n",i-1+cnt*m);
    }
    return 0;
}
