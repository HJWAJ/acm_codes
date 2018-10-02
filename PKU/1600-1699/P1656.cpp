#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    bool val[101][101];
    char s[10];
    int n,x,y,l,i,j,cnt;
    while(scanf("%d",&n)!=EOF)
    {
        memset(val,0,sizeof(val));
        while(n--)
        {
            scanf("%s%d%d%d",s,&x,&y,&l);
            if(s[0]=='W')
            {
                for(i=0;i<l;i++)
                    for(j=0;j<l;j++)
                        val[x+i][y+j]=0;             
            }
            else if(s[0]=='B')
            {
                for(i=0;i<l;i++)
                    for(j=0;j<l;j++)
                        val[x+i][y+j]=1;             
            }
            else
            {
                cnt=0;
                for(i=0;i<l;i++)
                    for(j=0;j<l;j++)
                        if(val[x+i][y+j]==1)cnt++;
                printf("%d\n",cnt);    
            }          
        }                          
    }    
    
    return 0;
}
