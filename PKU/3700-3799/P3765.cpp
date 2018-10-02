#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int n;
    char res[25][25],xy[10],s[5];
    int flag[9]={6,7,8,9,10,9,8,7,6},x,y,i,j;
    bool val[9];
    while(scanf("%d",&n) && n)
    {
        strcpy(res[0],"         _\n");
        strcpy(res[1],"       _/ \\_\n");
        strcpy(res[2],"     _/ \\_/ \\_\n");
        strcpy(res[3],"   _/ \\_/ \\_/ \\_\n");
        strcpy(res[4]," _/ \\_/ \\_/ \\_/ \\_\n");
        strcpy(res[5],"/ \\_/ \\_/ \\_/ \\_/ \\\n");
        strcpy(res[6],"\\_/ \\_/ \\_/ \\_/ \\_/\n");
        strcpy(res[7],"/ \\_/ \\_/ \\_/ \\_/ \\\n");
        strcpy(res[8],"\\_/ \\_/ \\_/ \\_/ \\_/\n");
        strcpy(res[9],"/ \\_/ \\_/ \\_/ \\_/ \\\n");
        strcpy(res[10],"\\_/ \\_/ \\_/ \\_/ \\_/\n");
        strcpy(res[11],"/ \\_/ \\_/ \\_/ \\_/ \\\n");
        strcpy(res[12],"\\_/ \\_/ \\_/ \\_/ \\_/\n");
        strcpy(res[13],"/ \\_/ \\_/ \\_/ \\_/ \\\n");
        strcpy(res[14],"\\_/ \\_/ \\_/ \\_/ \\_/\n");
        strcpy(res[15],"/ \\_/ \\_/ \\_/ \\_/ \\\n");
        strcpy(res[16],"\\_/ \\_/ \\_/ \\_/ \\_/\n");
        strcpy(res[17],"/ \\_/ \\_/ \\_/ \\_/ \\\n");
        strcpy(res[18],"\\_/ \\_/ \\_/ \\_/ \\_/\n");
        strcpy(res[19],"  \\_/ \\_/ \\_/ \\_/\n");
        strcpy(res[20],"    \\_/ \\_/ \\_/\n");
        strcpy(res[21],"      \\_/ \\_/\n");
        strcpy(res[22],"        \\_/\n");
        
        while(n--)
        {
            memset(s,0,sizeof(s));
            memset(xy,0,sizeof(xy));
            scanf("%s",xy);
            scanf("%s",s);
            x=xy[0]-'A';
            if(xy[2]=='0')y=10;
            else y=xy[1]-'0';
            res[22-(abs(x-4)+2*y+1)][x*2+1]=s[0];
        }                          
        
        for(i=0;i<23;i++)printf("%s",res[i]);
    }    
    
    return 0;
}
