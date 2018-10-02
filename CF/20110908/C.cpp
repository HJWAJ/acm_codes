#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
char s[100050];
int tmp[100005];
int check(int n)
{
    char tmp[15];
    memmove(tmp,s+n-4,4);
    tmp[4]='\0';
    if(!strcmp(tmp,"lios"))return 0;
    memmove(tmp,s+n-3,3);
    tmp[3]='\0';
    if(!strcmp(tmp,"etr"))return 1;
    memmove(tmp,s+n-6,6);
    tmp[6]='\0';
    if(!strcmp(tmp,"initis"))return 2;
    memmove(tmp,s+n-5,5);
    tmp[5]='\0';
    if(!strcmp(tmp,"liala"))return 3;
    memmove(tmp,s+n-4,4);
    tmp[4]='\0';
    if(!strcmp(tmp,"etra"))return 4;
    memmove(tmp,s+n-6,6);
    tmp[6]='\0';
    if(!strcmp(tmp,"inites"))return 5;
    return -1;
}
int main()
{
    memset(s,0,sizeof(s));
    int cnt=0,len,i,flag=0,gend;
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]==' ')
        {
            tmp[cnt]=check(i);
            if(flag==0)
            {
                gend=tmp[cnt]/3;
                flag=1;
            }
            cnt++;
        }
    tmp[cnt]=check(len);
    cnt++;
    if(cnt==1)
    {
        if(tmp[0]>=0)puts("YES");
        else puts("NO");
    }
    else
    {
        flag=0;
        if(gend==0)
        {
            for(i=0;i<cnt;i++)
            {
                if(tmp[i]>2 || tmp[i]<0)
                {
                    puts("NO");
                    break;
                }
                if(flag==0)
                {
                    if(tmp[i]==1)
                    {
                        flag=1;
                        i++;
                    }
                    else if(tmp[i]==2)
                    {
                        puts("NO");
                        break;
                    }
                }
                if(flag==1 && i<cnt)
                {
                    if(tmp[i]!=2)
                    {
                        puts("NO");
                        break;
                    }
                }
            }
            if(i>=cnt && flag==1)puts("YES");
        }
        else
        {
            flag=0;
            for(i=0;i<cnt;i++)
            {
                if(tmp[i]<3)
                {
                    puts("NO");
                    break;
                }
                if(flag==0)
                {
                    if(tmp[i]==4)
                    {
                        flag=1;
                        i++;
                    }
                    else if(tmp[i]==5)
                    {
                        puts("NO");
                        break;
                    }
                }
                if(flag==1 && i<cnt)
                {
                    if(tmp[i]!=5)
                    {
                        puts("NO");
                        break;
                    }
                }
            }
            if(i>=cnt && flag==1)puts("YES");
        }
    }
    return 0;
}
