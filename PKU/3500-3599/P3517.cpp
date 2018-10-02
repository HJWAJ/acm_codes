#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int m,n,k;

int ans(int num)
{
	if(num==1)return 0;
	return (k+ans(num-1))%num;
}

int main()
{
	while(scanf("%d%d%d",&n,&k,&m) && (n || k || m))printf("%d\n",(ans(n-1)+m)%n+1);
	return 0;
}
