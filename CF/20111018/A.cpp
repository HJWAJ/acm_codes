#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    char s[15];
    int n;
    scanf("%s%d",s,&n);
    if(!strcmp(s,"front"))
    {
        if(n==1)puts("L");
        else puts("R");
    }
    else
    {
        if(n==1)puts("R");
        else puts("L");
    }
	return 0;
}
