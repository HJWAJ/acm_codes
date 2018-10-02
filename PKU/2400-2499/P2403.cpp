#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int m,n,i,j,sum;
    char dict[1000][20],s[20];
    int val[1000];
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(dict,0,sizeof(dict));
        for(i=0;i<m;i++)scanf("%s%d",dict[i],val+i);
        for(j=0;j<n;j++)
        {
            sum=0;
            while(scanf("%s",s) && s[0]!='.')
            {
                for(i=0;i<m;i++)
                    if(strcmp(dict[i],s)==0)
                    {
                        sum+=val[i];
                        break;                        
                    }                    
            }
            printf("%d\n",sum);    
        }
    }    
    
    return 0;
}
