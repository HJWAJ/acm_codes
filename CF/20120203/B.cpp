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
using namespace std;
int main()
{
    double vp,vd,t,f,c,dis,time,cc;
    int cnt=0;
    scanf("%lf%lf%lf%lf%lf",&vp,&vd,&t,&f,&c);
    if(vp>=vd)
    {
        puts("0");
        return 0;
    }
    cc=c;
    dis=vp*t;
    c-=dis;
    while(c>0)
    {
        if(c<=0)break;
        time=dis/(vd-vp);
        c-=time*vp;
        if(c<=0)break;
        cnt++;
        c-=(time+f)*vp;
        if(c<=0)break;
        dis=cc-c;
    }
    printf("%d\n",cnt);
    return 0;
}
