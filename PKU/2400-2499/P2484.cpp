#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        if(n<3)puts("Alice");
        else puts("Bob");
    }
	return 0;
}
