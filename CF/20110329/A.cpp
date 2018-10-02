#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,len;
    char s[105];
    scanf("%d",&t);
    while(t--)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        len=strlen(s);
        if(len<=10)printf("%s\n",s);
        else printf("%c%d%c\n",s[0],len-2,s[len-1]);
    }    
    
    //system("pause");
    return 0;
}
