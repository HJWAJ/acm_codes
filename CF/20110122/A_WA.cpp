#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int t,cnt=0,len,i;
    char s[1005];
    char check[11][15]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    scanf("%d",&t);
    while(t--)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        len=strlen(s);
        if(s[0]>='0' && s[0]<='9')
        {
            if(len==2)
            {
                if(s[0]=='1' && s[1]<'8' && s[1]>='0')cnt++;       
            }             
            else if(len==1)cnt++;
        }         
        else
        {
            if(len>15)continue;
            for(i=0;i<11;i++)
                if(strcmp(s,check[i])==0){cnt++;break;}    
        }
        printf("%d\n",cnt);
    }
    
    //system("pause");    
    return 0;
}
