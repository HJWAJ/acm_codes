#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void work(char s[])
{
    int i,j,len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]==' ' && s[i+1]==' ')
        {
            for(j=i+2;j<len;j++)s[j-1]=s[j];
            s[len-1]='\0';
            i--;
        }     
}

int main()
{
    char s[1005];
    int len,i;
    gets(s);
    work(s);
    len=strlen(s);
    //for(i=0;i<len;i++)cout<<s[i];
    //cout<<endl;
    for(i=0;i<len;i++)
    {
        if(s[i]==' ' && s[i-1]>='0' && s[i-1]<='9' && s[i+1]>='0' && s[i+1]<='9')printf(" ");
        else if(s[i]==' ')continue;
        else if(s[i]==',' && i!=len-1)printf(", ");
        else if(s[i]==',' && i==len-1)printf(",");
        else if(s[i]=='.' && (i==0 || s[i-1]==',' || (i>1 && s[i-1]==' ' && s[i-2]==',')))
        {
            printf("...");
            i+=2;
        }
        else if(s[i]=='.')
        {
            printf(" ...");
            i+=2;     
        }
        else printf("%c",s[i]);                  
    }
    printf("\n");
    
    //system("pause");
    return 0;
}
