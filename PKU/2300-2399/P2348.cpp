#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return 0;
    if(a/b>=2)return 1;
    if(gcd(b,a%b))return 0;
    return 1;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b) && (a||b))
    {
        if(a<b)swap(a,b);
        if(gcd(a,b))puts("Stan wins");
        else puts("Ollie wins");
    }
    return 0;
}
