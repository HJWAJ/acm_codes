#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int Max=100001;
int eu[Max];
void eular()
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
    eular();
    int n;
    while(scanf("%d",&n)!=EOF)printf("%d\n",eu[eu[n]]);
    return 0;
}
