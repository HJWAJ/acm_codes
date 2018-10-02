#include<stdio.h>
#include<string.h>

int main()
{
    char s[1005];
    while(gets(s))
    {
        int len=strlen(s);
        int i;
        for(i=0;i<len;i++)
        {
            if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u')
            {
                printf("we");
                i+=2;             
            }
            else printf("%c",s[i]);                    
        }
        printf("\n");                        
    }    
    return 0;
}
