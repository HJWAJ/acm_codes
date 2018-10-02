#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    char s[]="0123456789";
    int cnt=1;
    while(1)
    {
        cnt++;
        next_permutation(s,s+10);
        if(cnt==1000000)break;
    }
    puts(s);
    return 0;
}
