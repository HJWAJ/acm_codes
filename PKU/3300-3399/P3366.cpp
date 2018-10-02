#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool iscon(char ch)
{
    char s[]="qwrtypsdfghjklzxcvbnm";
    int i,len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]==ch)return 1;
    return 0;     
}

int main()
{
    char dict[20][100],dict1[20][100],s[100];
    int m,n,i,len;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)scanf("%s%s",dict[i],dict1[i]);
    while(n--)
    {
        scanf("%s",s);
        for(i=0;i<m;i++)
            if(strcmp(s,dict[i])==0)
            {
                printf("%s\n",dict1[i]);
                goto label;                        
            }          
        len=strlen(s);
        if(len>1 && iscon(s[len-2]) && s[len-1]=='y')
        {
            s[len-1]='\0';
            printf("%sies\n",s);                 
        }
        else if(len>1 && s[len-1]=='h' && (s[len-2]=='c' || s[len-2]=='s'))printf("%ses\n",s);
        else if(s[len-1]=='o' ||s[len-1]=='s' ||s[len-1]=='x')printf("%ses\n",s);
        else printf("%ss\n",s);
        label:;
    }    
    
    //system("pause");
    return 0;
}
