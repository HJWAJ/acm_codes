#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,i,j,k,t,cnt;
    bool val[7][7][7][7];
    char a[3][3];
    while(scanf("%d",&n)!=EOF)
    {
        memset(val,0,sizeof(val));
        cnt=0;
        for(i=0;i<n-1;i++)
        {
            scanf("%s%s%s",a[0],a[1],a[2]);
            val[a[0][0]-'0'][a[0][1]-'0'][a[1][0]-'0'][a[1][1]-'0']=1;
        }        
        scanf("%s%s",a[0],a[1]);
        val[a[0][0]-'0'][a[0][1]-'0'][a[1][0]-'0'][a[1][1]-'0']=1;
        for(i=0;i<7;i++)
            for(j=0;j<7;j++)
                for(k=0;k<7;k++)
                    for(t=0;t<7;t++)
                    {
                        if(val[i][j][k][t]==1)
                        {
                            cnt++;
                            val[i][j][k][t]=0;
                            val[j][t][i][k]=0;
                            val[t][k][j][i]=0;
                            val[k][i][t][j]=0;                      
                        }                
                    } 
        printf("%d\n",cnt);  
    }    
    
    return 0;
}
