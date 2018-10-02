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
const double pi=3.14159;
int main()
{
    int x,y,z;
    double alpha,L,L1,Y;
    char s[15];
    while(scanf("%s",s) && strcmp(s,"ENDOFINPUT"))
    {
        scanf("%d%d%d",&x,&y,&z);
        scanf("%s",s);
        if(z>180)z=360-z;
        alpha=z*pi/180.0;
        L=alpha*x*2.0;
        L1=y*5.0;
        Y=y-L/5.0;
        if(L1>=L)printf("YES %d\n",int(Y));
        else printf("NO %d\n",int(L1));
    }
}
