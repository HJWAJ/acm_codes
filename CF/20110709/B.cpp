#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int a[4][10005];
int flag[4];
int atoi(char s[])
{
    int len=strlen(s);
    int i,num=0;
    for(i=0;i<len;i++)
    {
        num*=10;
        num+=(s[i]-'0');
    }
    return num;
}
void dabiao()
{
    int i,j,tmp;
    char s[10];
    for(i=0;i<4;i++)
    {
        for(j=0;j<i+1;j++)s[j]='4';
        for(;j<2*(i+1);j++)s[j]='7';
        s[2*i+2]='\0';
        tmp=atoi(s);
        a[i][0]=tmp;
        flag[i]=0;
        while(1)
        {
            next_permutation(s,s+2*(i+1));
            tmp=atoi(s);
            if(tmp>a[i][flag[i]])
            {
                flag[i]++;
                a[i][flag[i]]=tmp;
            }
            else
            {
                flag[i]++;
                break;
            }
        }
    }
}
int main()
{
    char s[105];
    int len,i,j,num,num0;
    dabiao();
    /*
    for(i=0;i<4;i++)
    {
        for(j=0;j<flag[i];j++)printf("%d ",a[i][j]);
        printf("\n");
    }
    */
    scanf("%s",s);
    len=strlen(s);
    if(len&1)
    {
        for(i=0;i<(len+1)/2;i++)printf("4");
        for(i=0;i<(len+1)/2;i++)printf("7");
        printf("\n");
    }
    else if(len==10)
    {
        puts("4444477777");
    }
    else
    {
        num=0;
        for(i=0;i<len;i++)
        {
            num*=10;
            num+=(s[i]-'0');
        }
        num0=0;
        for(i=0;i<len/2;i++)
        {
            num0*=10;
            num0+=7;
        }
        for(i=0;i<len/2;i++)
        {
            num0*=10;
            num0+=4;
        }
        if(num>num0)
        {
            for(i=0;i<=len/2;i++)printf("4");
            for(i=0;i<=len/2;i++)printf("7");
            printf("\n");
        }
        else
        {
            for(i=0;i<flag[len/2-1];i++)
                if(a[len/2-1][i]>=num)
                {
                    printf("%d\n",a[len/2-1][i]);
                    break;
                }
        }
    }
    return 0;
}
