#include<iostream>
using namespace std;

int main()
{
    char s[1000];
    int num[1000],i;
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s);
        memset(num,0,sizeof(num));
        for(i=len-1;i>=0;i--)num[len-1-i]=int(s[i]-'0');
        for(i=0;i<len;i++)num[i]*=(len+1);     
        for(i=0;i<len;i++)if(num[i]>=10){num[i+1]=num[i+1]+num[i]/10;num[i]%=10;}
        for(i=0;i<len;i++)if(num[i]!=9)break;
        if(i==len)printf("%s is cyclic\n",s);
        else printf("%s is not cyclic\n",s);
        
    }    
    
    system("pause");
    return 0;
}
