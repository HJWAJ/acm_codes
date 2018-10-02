/*
ID: hjw00002
PROG: transform
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

bool issame(char s[][15],char s1[][15],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(s[i][j]!=s1[i][j])return 0;
    return 1;     
}

void turn90(char s[][15],char s1[][15],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            s1[n-1-j][i]=s[i][j];     
}

void turn180(char s[][15],char s1[][15],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            s1[n-1-i][n-1-j]=s[i][j];
}

void turn270(char s[][15],char s1[][15],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            s1[j][n-1-i]=s[i][j];     
}

void turnto(char s[][15],char s1[][15],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            s1[i][n-1-j]=s[i][j]; 
}

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    int n,i;
    char s[15][15],s1[15][15],s2[15][15],s3[15][15];
    memset(s,0,sizeof(s));
    memset(s1,0,sizeof(s1));
    memset(s2,0,sizeof(s2));
    memset(s3,0,sizeof(s3));
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)scanf("%s",s1[i]);
    
    /*/
    for(i=0;i<n;i++)printf("%s",s[i]);
    for(i=0;i<n;i++)printf("%s",s1[i]);
    //*/
    
        turn90(s1,s2,n);
        if(issame(s,s2,n))printf("1\n");
        else
        {
            turn180(s1,s2,n);
            if(issame(s,s2,n))printf("2\n");
            else
            {
                turn270(s1,s2,n);
                if(issame(s,s2,n))printf("3\n");
                else
                {
                    turnto(s1,s2,n);
                    if(issame(s,s2,n))printf("4\n");
                    else
                    {
                        turn90(s2,s3,n);
                        if(issame(s,s3,n))printf("5\n");
                        else
                        {
                            turn180(s2,s3,n);
                            if(issame(s,s3,n))printf("5\n");
                            else
                            {
                                turn270(s2,s3,n);
                                if(issame(s,s3,n))printf("5\n");
                                else 
                                {
                                     if(issame(s,s1,n))printf("6\n");
                                     else printf("7\n");       
                                }    
                            }    
                        }    
                    }    
                }    
            }    
        }    
    
    //system("pause");
    return 0;
}
