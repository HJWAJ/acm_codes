#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool is(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')return 1;
    return 0;     
}

int main()
{
    int t,len,i;
    char s[10005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(is(s[i]) && s[i]>='a' && s[i]<='z')s[i]+=('A'-'a');
            if(!is(s[i]) && s[i]>='A' && s[i]<='Z')s[i]+=('a'-'A');                  
        }          
        printf("%s\n",s);
    }
    
    return 0;
}
