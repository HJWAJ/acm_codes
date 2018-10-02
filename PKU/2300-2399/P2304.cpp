#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int start,a,b,c,res;
    while(scanf("%d%d%d%d",&start,&a,&b,&c) && (a||b||c||start))
    {
        res=1080;
        if(start<a)res+=((start+40-a)*9);
        else res+=((start-a)*9);
        if(a<b)res+=((b-a)*9);
        else res+=((b+40-a)*9);
        if(b<c)res+=((b+40-c)*9);
        else res+=((b-c)*9);
        printf("%d\n",res);                        
    }    
    
    return 0;
}
