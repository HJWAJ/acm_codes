#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char s[100000];

int main()
{
    char str[5050];
    while(scanf("%s",str)!=EOF)
    {
        strcat(s,str);                      
    }
    
    /*/
    printf("%s\n",s);
    system("pause");
    //*/
    
    int len=strlen(s),i,j,flag=0;
    int cnt[10000],stack[10000],k=0;
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<len;i++)
    {
        if(s[i]!='/' && s[i+1]=='t' && s[i+2]=='a' && s[i+3]=='b' && s[i+4]=='l' && s[i+5]=='e'){stack[flag]=1;flag++;}
        if(s[i]!='/' && s[i+1]=='t' && s[i+2]=='d'){stack[flag]=2;flag++;}
        if(s[i]=='/' && s[i+1]=='t' && s[i+2]=='a' && s[i+3]=='b' && s[i+4]=='l' && s[i+5]=='e')
        {
            while(stack[flag-1]==2){cnt[k]++;flag--;}
            flag--;k++;
        }
    }
    
    sort(cnt,cnt+k);
    for(i=0;i<k;i++)printf("%d ",cnt[i]);
    printf("\n");
    //system("pause");
    return 0;
}
