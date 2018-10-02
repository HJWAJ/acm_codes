#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int data[100000];
char s[10];

int main()
{
    int t,i,k;
    while(scanf("%d",&t)!=EOF)
    {
        for(i=0;i<t;i++)scanf("%d",&data[i]);
        scanf("%s",s);
        sort(data,data+t);
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
            scanf("%d",&k);
            printf("%d\n",data[k-1]);                
        }                       
    }    
    
    return 0;
}
