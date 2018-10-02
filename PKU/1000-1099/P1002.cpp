#include<iostream>
#include<cstring>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
using namespace std;

char map(char s)
{
    char a;
    switch(s){
    case '0':a='0';break;
    case '1':a='1';break;
    case 'A': case 'B': case 'C':case '2':a='2';break;
    case 'D': case 'E': case 'F':case '3':a='3';break;
    case 'G': case 'H': case 'I':case '4':a='4';break;
    case 'J': case 'K': case 'L':case '5':a='5';break;
    case 'M': case 'N': case 'O':case '6':a='6';break;
    case 'P': case 'R': case 'S':case '7':a='7';break;
    case 'T': case 'U': case 'V':case '8':a='8';break;
    case 'W': case 'X': case 'Y':case '9':a='9';break;        
    } 
    return a;
}

int a_to_i(char *s)
{
    int a=0;
    for(int i=0;i<7;i++)
    {
        a*=10;
        a+=(s[i]-'0');
    }
    return a;    
}

int memo[10000000];

int main()
{
    memset(memo,0,sizeof(memo));
    int numb[50000];
    int t,i,j,k;
    char str[100];
    char ans[100];
    scanf("%d",&t);
    
    while(t--)
    {
        k=0;
        memset(str,0,sizeof(str));
        scanf("%s",str);
        int len=strlen(str);
        for(j=0;j<len;j++)
            if((str[j]>='A' && str[j]<='Z' && str[j]!='Q' && str[j]!='Z') || (str[j]>='0' && str[j]<='9'))
            {    
                 ans[k]=map(str[j]);
                 k++;
            }
        memo[a_to_i(ans)]++;
    }
    bool value=0;
    for(i=0;i<10000000;i++)
    {
        if(memo[i]>1)
        {
            printf("%03d-%04d %d\n",i/10000,i%10000,memo[i]);
            value=1;
        }                       
    }
    if(value==0){printf("No duplicates.\n");goto label;}
    
    label:;
    system("pause");
    return 0;
}
