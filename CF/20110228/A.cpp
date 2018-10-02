#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct poeple 
{
    char name[100];
    char s[10];       
}peo[1000];

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s%s",peo[i].name,peo[i].s);
    for(i=0;i<n;i++)
        if(peo[i].s[0]=='r')printf("%s\n",peo[i].name);
    for(i=0;i<n;i++)
        if(peo[i].s[0]=='w' || (peo[i].s[0]=='c' && peo[i].s[1]=='h'))printf("%s\n",peo[i].name);
    for(i=0;i<n;i++)
        if(peo[i].s[0]=='m')printf("%s\n",peo[i].name);
    for(i=0;i<n;i++)
        if(peo[i].s[0]=='c' && peo[i].s[1]=='a')printf("%s\n",peo[i].name);
        
    //system("pause");
    return 0;
}
