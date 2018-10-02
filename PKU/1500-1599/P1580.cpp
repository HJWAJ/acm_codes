#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <memory.h>
using namespace std;
char s1[1005],s2[1005];
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int calc(char *s1,char *s2,int len1,int len2)
{
    int res=0,i,len;
    len=(len1>len2?len2:len1);
    for(i=0;i<len;i++)
        if(s1[i]==s2[i])res++;
    return res;
}
int main()
{
	int max,len1,len2,i,tmp,d,len;
	while(scanf("%s",s1) && strcmp(s1,"-1"))
    {
        scanf("%s",s2);
        max=0;
        len1=strlen(s1);
        len2=strlen(s2);
        for(i=0;i<len1;i++)
        {
            tmp=calc(s1+i,s2,len1-i,len2);
            if(tmp>max)max=tmp;
        }
        for(i=0;i<len2;i++)
        {
            tmp=calc(s1,s2+i,len1,len2-i);
            if(tmp>max)max=tmp;
        }
        max*=2;
        len=len1+len2;
        d=gcd(max,len);
        max/=d;
        len/=d;
        printf("appx(%s,%s) = ",s1,s2);
        if(max==0)puts("0");
        else if(max==len)puts("1");
        else printf("%d/%d\n",max,len);
    }
	return 0;
}
