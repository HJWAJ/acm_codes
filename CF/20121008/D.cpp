#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
using namespace std;
int main()
{
    int x,y,z,xx,yy,zz,a,b,c,d,e,f,sum=0;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x,&y,&z,&xx,&yy,&zz,&a,&b,&c,&d,&e,&f);
    if(x<0)sum+=e;
    if(x>xx)sum+=f;
    if(y<0)sum+=a;
    if(y>yy)sum+=b;
    if(z<0)sum+=c;
    if(z>zz)sum+=d;
    printf("%d\n",sum);
	return 0;
}
