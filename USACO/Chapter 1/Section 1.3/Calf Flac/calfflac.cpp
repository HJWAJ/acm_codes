/*
ID: hjw00002
PROG: calfflac
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

bool isnlegal(char s)
{
    if((s>='A' && s<='Z') || (s>='a' && s<='z'))return 0;
    return 1;
}

int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    char s[20050],str[20050],palin[20050];
    int len,palinlen,flag,flagl,flagr,flag1,flag2,flagx,flagy,i,j=0,max=0;
    while(gets(str))
    {
        strcat(s,str);
        s[strlen(s)]='\n';
    }
    len=strlen(s);
    flag=1;
    while(flag<len)
    {
        flagl=flagr=flag;
        palinlen=1;
        flagl--;
        flagr++;
        while(flagl>=0 && flagr<len)
        {
            while(isnlegal(s[flagl]))
            {
                flagl--;
                if(flagl<0){flagl++;break;}
            }
            while(isnlegal(s[flagr]))
            {
                flagr++;
                if(flagr>=len){flagr--;goto label;}                      
            }
            if(s[flagl]==s[flagr] || s[flagl]==s[flagr]+'A'-'a' || s[flagl]==s[flagr]+'a'-'A')
            {
                flagx=flagl;
                flagy=flagr;
                flagl--;
                flagr++;
                palinlen+=2;                      
            }
            else break;
        }
        label:;
        if(isnlegal(s[flag]))palinlen--;         
        if(max<palinlen)
        {
            max=palinlen;
            flag1=flagx;
            flag2=flagy;
            memset(palin,0,sizeof(palin));
            for(i=0;i<=flag2-flag1;i++)palin[i]=s[i+flag1];                
        }
        
        if(s[flag]==s[flag+1] && !isnlegal(s[flag]))
        {
            flagl=flag;
            flagr=flag+1;
            palinlen=2;
            flagl--;
            flagr++;
            while(flagl>=0 && flagr<len)
            {
                while(isnlegal(s[flagl]))
                {
                    flagl--;
                    if(flagl<0){flagl++;break;}
                }
                while(isnlegal(s[flagr]))
                {
                    flagr++;
                    if(flagr>=len){flagr--;goto label1;}                      
                }
                if(s[flagl]==s[flagr] || s[flagl]==s[flagr]+'A'-'a' || s[flagl]==s[flagr]+'a'-'A')
                {
                    flagx=flagl;
                    flagy=flagr;
                    flagl--;
                    flagr++;
                    palinlen+=2;                      
                }
                else break;
            }
            label1:;
            if(isnlegal(s[flag]))palinlen--;         
            if(max<palinlen)
            {
                max=palinlen;
                flag1=flagx;
                flag2=flagy;
                memset(palin,0,sizeof(palin));
                for(i=0;i<=flag2-flag1;i++)palin[i]=s[i+flag1];                
            }                      
        }
        flag++;      
    }
    printf("%d\n%s\n",max,palin);
    
    //system("pause");
    return 0;
}
