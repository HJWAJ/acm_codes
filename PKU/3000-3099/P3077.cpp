#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)    
    {
        char s[10];
        memset(s,0,sizeof(s));
        scanf("%s",s);
        int len=strlen(s);
        int i;
        for(i=len-1;i>0;i--)
        {
            if(s[i]>='5' && s[i]<='9')s[i-1]++;
            s[i]='0';                     
        }              
        for(i=len-2;i>0;i--)
            if(s[i]>'9')
            {
                s[i]=char(s[i]-10);
                s[i-1]++;
            }
        for(i=0;i<len;i++)
            printf("%d",int(s[i]-'0'));
        printf("\n");
    }
    
    system("pause");
    return 0;
}
