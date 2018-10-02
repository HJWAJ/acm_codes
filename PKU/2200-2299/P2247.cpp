#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
using namespace std;
long long int min(long long int a,long long int b,long long int c,long long int d)
{
     long long int min=a;
     if(min>b)min=b;
     if(min>c)min=c;
     if(min>d)min=d;
     return min;
}
int main()
{
    int i=1,j=1,k=1,l=1,m=1;
    long long int p[5850];
    p[1]=1;
    for(m=2;m<=5842;m++)
    {
         p[m]=min(p[i]*2,p[j]*3,p[k]*5,p[l]*7);
         if(p[m]==p[i]*2)i++;
         if(p[m]==p[j]*3)j++;
         if(p[m]==p[k]*5)k++;
         if(p[m]==p[l]*7)l++;
    }
    int n;
    while(scanf("%d",&n) && n)
    {
        if(n%10==1 && n%100!=11)printf("The %dst humble number is %lld.\n",n,p[n]);
        else if(n%10==2 && n%100!=12)printf("The %dnd humble number is %lld.\n",n,p[n]);
        else if(n%10==3 && n%100!=13)printf("The %drd humble number is %lld.\n",n,p[n]);
        else printf("The %dth humble number is %lld.\n",n,p[n]);
    }
	return 0;
}
