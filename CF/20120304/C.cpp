#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
char ins[5],s[305],ans[10005],tmp[305];
int anslen=0,len;
int main()
{
    int n,i,flag;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",ins);
        if(!strcmp(ins,"pwd"))
        {
            ans[anslen]='\0';
            printf("%s",ans);
            puts("/");
        }
        else
        {
            scanf("%s",s);
            len=strlen(s);
            i=flag=0;
            if(s[0]=='/')
            {
                anslen=0;
                i++;
                flag++;
            }
            while(i<len)
            {
                if(s[i]!='/')i++;
                else
                {
                    memset(tmp,0,sizeof(tmp));
                    strncpy(tmp,s+flag,i-flag);
                    //puts(tmp);
                    if(strcmp(tmp,".."))
                    {
                        strcpy(ans+anslen,"/");
                        anslen++;
                        strcpy(ans+anslen,tmp);
                        anslen+=strlen(tmp);
                    }
                    else
                    {
                        while(ans[anslen]!='/')anslen--;
                        ans[anslen]='\0';
                    }
                    i++;
                    flag=i;
                }
            }
            memset(tmp,0,sizeof(tmp));
            strncpy(tmp,s+flag,i-flag);
            //puts(tmp);
            //cout<<anslen<<endl;
            if(strcmp(tmp,".."))
            {
                strcpy(ans+anslen,"/");
                anslen++;
                //puts(ans);
                strcpy(ans+anslen,tmp);
                anslen+=strlen(tmp);
                //puts(ans);
            }
            else
            {
                while(ans[anslen]!='/')anslen--;
                ans[anslen]='\0';
            }
        }
    }
    return 0;
}
