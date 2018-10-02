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
bool in(int a,int b)
{
    int aa[10],bb[10],lena,lenb;
    memset(aa,0,sizeof(aa));
    memset(bb,0,sizeof(bb));
    int i=0;
    while(a)
    {
        aa[i]=a%10;
        a/=10;
        i++;
    }
    lena=i;
    i=0;
    while(b)
    {
        bb[i]=b%10;
        b/=10;
        i++;
    }
    lenb=i;
    int flaga=0,flagb=0;
    while(flagb!=lenb)
    {
        if(aa[flaga]==bb[flagb])
        {
            flaga++;
            flagb++;
        }
        else flaga++;
        if(flaga==lena && flagb!=lenb)return 0;
    }
    return 1;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    do
    {
        a++;
    }while(!in(a,b));
    printf("%d\n",a);
    return 0;
}
