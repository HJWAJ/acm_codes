#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int sushu[50000];
bool dabiao[200001];
char s[50000][10],s1[10000][10],s2[5000][10],ans[5][5];

void sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j,flag=0;  
    for(i=2;i<=100000;i++)
        if(dabiao[i]==0)
        {
            sushu[flag++]=i;
            for(j=2;j<=100000/i;j++)dabiao[j*i]=1;
        }  
}

void int2str(char str[],int n)
{
    int i=0,j;
    while(n)
    {
        str[i++]=char(n%10+'0');
        n/=10;        
    }     
    for(j=0;j<i/2;j++)swap(str[j],str[i-j-1]);
}

int main()
{
    sushubiao();
    int sum,n,i,j,k,flag;
    memset(s,0,sizeof(s));
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    i=0;
    while(sushu[i]<10000)i++;
    flag=0;
    while(sushu[i]<100000)
    {
        int2str(s[flag++],sushu[i]);
        i++;
    }
    scanf("%d%d",&sum,&n);
    j=k=0;
    for(i=0;i<flag;i++)
        if(s[i][0]+s[i][1]+s[i][2]+s[i][3]+s[i][4]-5*'0'==sum)
        {
            strcpy(s1[j],s[i]);
            j++;
            if((s1[i][0]&1) && (s1[i][1]&1) && (s1[i][2]&1) && (s1[i][3]&1) && (s1[i][4]&1))
            {
                strcpy(s2[k],s1[j]);
                k++;
            }                                       
        }
    
    
    system("pause");
    return 0;
}
