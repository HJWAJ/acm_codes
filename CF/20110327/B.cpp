#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,i,len,flag,val,flag0,tmpflag,cnt=0;
    char s[10005];
    scanf("%d",&n);
    getchar();
    gets(s);
    len=strlen(s);
    flag0=-1;
    for(i=0;i<len;i++)
        if(s[i]=='.' || s[i]=='?' || s[i]=='!'){tmpflag=i;break;}
    if(tmpflag-flag0>n){printf("Impossible\n");goto label;}
    for(;i<len;i++)
    {
        if(s[i]=='.' || s[i]=='?' || s[i]=='!')flag=i;
        if(flag-flag0>n)
        {
            cnt++;
            flag0=tmpflag+1;
            tmpflag=flag;
            if(tmpflag-flag0-1>n){printf("Impossible\n");goto label;}               
        }
        else
        {
            tmpflag=flag;    
        }
    }
    cnt++;
    printf("%d\n",cnt);
    label:;
    //system("pause");
    return 0;
}
