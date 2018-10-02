#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<ctime>
using namespace std;
int main()
{
    int a,b,c,flag=0,len;
    char ans[15];
    memset(ans,0,sizeof(ans));
    scanf("%d%d",&a,&b);
    c=a+b;
    if(c<0)flag=1;
    sprintf(ans,"%d",c);
    len=strlen(ans+flag);
    if(len%3)flag+=len%3;
    else flag+=3;
    //cout<<flag<<endl;
    while(flag<strlen(ans))
    {
        memmove(ans+flag+1,ans+flag,strlen(ans+flag));
        ans[flag]=',';
        flag+=4;
        //puts(ans);
    }
    puts(ans);
    return 0;
}
