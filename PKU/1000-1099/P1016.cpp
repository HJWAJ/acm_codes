#include<iostream>
#include<cstring>
using namespace std;

char strr[100];
int cnt[10];

void turn(char* s)
{
    int i,j=0;
    memset(cnt,0,sizeof(cnt));
    memset(strr,0,sizeof(strr));
    int len=strlen(s);
    for(i=0;i<len;i++)cnt[s[i]-'0']++;  
    for(i=0;i<10;i++)
    {
        if(cnt[i]>0)
        {
            if(cnt[i]>=10)
            {
                strr[j]=char(cnt[i]/10+'0'); 
                strr[j+1]=char(cnt[i]%10+'0');
                j+=2; 
            }        
            else
            {
                strr[j]=char(cnt[i]+'0');
                j++;
            }  
            strr[j]=char(i+'0');
            j++;
        }                 
    }    
}

int main()
{
    char str[16][100];
    memset(str,0,sizeof(str));
    int i,flag=0,value=0;
    while(scanf("%s",str[0]) && str[0][0]!='-')
    {
        for(i=1;i<=15;i++)
        {
            turn(str[i-1]);
            strcpy(str[i],strr);
            if(strcmp(str[i],str[0])==0){flag=1;break;}
            if(strcmp(str[i],str[i-1])==0){flag=2;break;}
        }
        if(i==16 && flag==0)
        {
            value=0;
            for(i=13;i>0;i--)
                if(strcmp(str[15],str[i])==0){value=1;i=15-i;break;}         
        }
        if(strcmp(str[0],str[1])==0)printf("%s is self-inventorying\n",str[0]);
        else if(flag==1 || value==1)printf("%s enters an inventory loop of length %d\n",str[0],i);
        else if(flag==2)printf("%s is self-inventorying after %d steps\n",str[0],i-1);
        else printf("%s can not be classified after 15 iterations\n",str[0]);
        memset(str,0,sizeof(str)); 
        flag=0;
        value=0;                      
    }    
    
    system("pause");
    return 0;
}
