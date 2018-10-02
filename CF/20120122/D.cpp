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
    int a,b,c,d,i;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(c-1>d || d-1>c)puts("-1");
    else if(a<c || a<d || b<c || b<d)puts("-1");
    else
    {
        if(c==0 && d==0)
        {
            if(a!=0 && b!=0)puts("-1");
            else
            {
                for(i=0;i<a;i++)printf("4");
                for(i=0;i<b;i++)printf("7");
            }
        }
        else if(c==0)
        {
            for(i=0;i<b;i++)printf("7");
            for(i=0;i<a;i++)printf("4");
            puts("");
        }
        else if(d==0)
        {
            for(i=0;i<a;i++)printf("4");
            for(i=0;i<b;i++)printf("7");
        }
        else if(c>d)
        {
            for(i=0;i<a-c;i++)printf("4");
            for(i=0;i<c;i++)printf("47");
            for(i=0;i<b-c;i++)printf("7");
            puts("");
        }
        else if(c==d)
        {
            if(a==c && b==c)puts("-1");
            else if(a==c)
            {
                for(i=0;i<a;i++)printf("74");
                for(i=0;i<b-a;i++)printf("7");
                puts("");
            }
            else
            {
                for(i=0;i<a-c;i++)printf("4");
                for(i=0;i<c-1;i++)printf("74");
                for(i=0;i<b-c+1;i++)printf("7");
                puts("4");
            }
        }
        else
        {
            printf("74");
            for(i=0;i<a-c-1;i++)printf("4");
            for(i=0;i<c-1;i++)printf("74");
            for(i=0;i<b-d;i++)printf("7");
            puts("74");
        }
    }
    return 0;
}
