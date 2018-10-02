/*
ID: hjw00002
PROG: beads
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    
    int len,i,max=0,maxi,cnt,cnt1,cnt2;
    char str[2000],s[2000];
    memset(str,0,sizeof(str));
    scanf("%d%s",&len,str);
    for(i=0;i<len;i++)str[2*len+i]=str[len+i]=str[i];
    i=0;
    for(i=len;i<2*len;i++)
    {
        cnt=cnt1=cnt2=0;
        memcpy(s,str,sizeof(str));
        if(s[i]=='w')
        {
            while(s[i+cnt]=='w')cnt++;
            s[i]=s[i+cnt];
            cnt=0;             
        }
        while(s[i]==s[i+cnt1] || s[i+cnt1]=='w')cnt1++;
        if(s[i-1]=='w')
        {
            while(s[i-1-cnt]=='w')cnt++;
            s[i-1]=s[i-1+cnt];
            cnt=0;             
        }
        while(s[i-1]==s[i-1-cnt2] || s[i-1-cnt2]=='w')cnt2++;
        cnt=cnt1+cnt2;
        if(max<cnt)max=cnt;
        if(max>=len){max=len;printf("%d\n",max);return 0;}             
    }
    printf("%d\n",max);
    
    //system("pause");
    return 0;
}
