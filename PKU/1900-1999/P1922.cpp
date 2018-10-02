#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int n,v,t,i,tmin;
    while(scanf("%d",&n) && n!=0)
    {
        tmin=0x7fffffff;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&v,&t);
            if(t<0)continue;
            t=(int)ceil(4.5*3600/double(v)+t);
            if(tmin>t)tmin=t;
        }
        printf("%d\n",tmin);
    }    
    
    return 0;
}
