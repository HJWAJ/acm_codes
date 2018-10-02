#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[1005];
    int cnt1,cnt2,cnt3,len,i;
    cnt1=cnt2=cnt3=0;
    memset(s,0,sizeof(s));
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')cnt1++;
    memset(s,0,sizeof(s));
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')cnt2++;
    memset(s,0,sizeof(s));
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')cnt3++;
    if(cnt1==5 && cnt2==7 && cnt3==5)printf("YES\n");
    else printf("NO\n");
    
    //system("pause");    
    return 0;
}
