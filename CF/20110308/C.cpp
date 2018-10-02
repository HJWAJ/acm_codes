#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char files[105][105];
char filename[105][105];
char s[105],tmpfiles[105],tmpfilename[105];

int main()
{
    int flag1=0,flag2=0,len,cnt,i,j,num;
    memset(files,0,sizeof(files));
    memset(filename,0,sizeof(filename));
    memset(s,0,sizeof(s));
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        num=cnt=0;
        for(i=0;i<lrn;i++)if(s[i]=='\\')num++;
        for(i=0;i<len;i++)
        {
            if(s[i]=='\\')
            {
                if(cnt==num)
                {
                j=i+1;
                while(s[j]!='\\')tmpfilename[j-1-i]=s[j];
                for(j=0;j<flag;j++)
                    if(strcmp(filename[cnt],tmpfilename)==0)break;
                if(j==flag){strcpy(filename[flag],tmpfilename);flag++;}            
                }
                else
                {
                j=i+1;
                while(s[j]!='\\')tmpfiles[j-1-i]=s[j];
                for(j=0;j<flag;j++)
                    if(strcmp(files[cnt],tmpfiles)==0)break;
                if(j==flag){strcpy(files[flag],tmpfiles);flag++;}
                }
                cnt++;              
            }                  
        }
        memset(s,0,sizeof(s));             
    }
    
    
    system("pause");
    return 0;
}
