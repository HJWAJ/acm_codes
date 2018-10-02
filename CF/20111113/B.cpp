#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int a[9]={0,1,2,6,24,120,720,5040,40320};
int ord[10]={0,1,2,3,4,5,6,7,8,9};
int getnum(char s1[],char s2[],int len)
{
    int a=0,b=0,i;
    for(i=0;i<len;i++)
    {
        a*=10;
        a+=(s1[i]-'0');
        b*=10;
        b+=(s2[i]-'0');
    }
    //cout<<b<<' '<<a<<endl;
    return b-a;
}
void order(char s[],char ss[],int k)
{
    int i;
    memset(ss,0,sizeof(ss));
    for(i=0;i<k;i++)ss[ord[i]]=s[i];
}
int main()
{
    char s[15][15],min[15],max[15],str[15][15];
    int n,k,i,cnt=0,mini=999999999,dis;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    memmove(str,s,sizeof(s));
    while(cnt<a[k])
    {
        strcpy(min,str[0]);
        strcpy(max,str[0]);
        for(i=1;i<n;i++)
        {
            if(strcmp(min,str[i])>0)strcpy(min,str[i]);
            if(strcmp(max,str[i])<0)strcpy(max,str[i]);
        }
        dis=getnum(min,max,k);
        if(dis<mini)mini=dis;
        next_permutation(ord,ord+k);
        for(i=0;i<n;i++)order(s[i],str[i],k);
        cnt++;
    }
    printf("%d\n",mini);
	return 0;
}
