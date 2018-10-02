#include<iostream>
using namespace std;

int main()
{
    int val[4][4];
    char s[4][5];
    int cnt=0,i,j,k;
    memset(val,0,sizeof(val));
    for(i=0;i<4;i++)
    {
        scanf("%s",&s[i]);
        //printf("%s\n",s[i]);
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(s[i][j]=='+')
            {
                val[i][j]++;
                for(k=0;k<4;k++)
                    val[i][k]++;
                for(k=0;k<4;k++)
                    val[k][j]++;  
                
                /*
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",val[i][j]);
        printf("\n");                
    }  
    //*/  
    //system("pause"); 
            }
    
    /*
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d ",val[i][j]);
        printf("\n");                
    }  
    //*/      
    
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
           val[i][j]%=2;
           if(val[i][j]==1)cnt++;
        }
    printf("%d\n",cnt);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(val[i][j]==1)printf("%d %d\n",i+1,j+1);
            
     
    
    system("pause");
    return 0;
}
