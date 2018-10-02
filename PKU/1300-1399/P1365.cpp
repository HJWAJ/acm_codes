#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int sushu[50000];
bool dabiao[200001];

int sushubiao()
{
    memset(sushu,0,sizeof(sushu));
    memset(dabiao,0,sizeof(dabiao));
    dabiao[0]=1;
    dabiao[1]=1;
    int num;
    int i,j,flag=0;  
    for(i=2;i<=50000;i++)
        if(dabiao[i]==0)
        {
            sushu[flag++]=i;
            for(j=2;j<=50000/i;j++)dabiao[j*i]=1;
        }
    return flag;  
}

int main()
{
    char s[10005];
    int num[1005],len,flag,i,j,ans,cnt1,cnt,val;
    cnt1=sushubiao();
    memset(s,0,sizeof(s));
    while(gets(s) && strcmp(s,"0"))
    {
        memset(num,0,sizeof(num));
        flag=0;
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]!=' ')
            {
                num[flag]*=10;
                num[flag]+=(s[i]-'0'); 
            }
            else flag++;            
        }
        flag++;
        ans=1;
        for(i=0;i<flag/2;i++)
        {
            for(j=0;j<num[2*i+1];j++)
                ans*=num[2*i];                     
        }
        //printf("%d\n",ans);
        cnt=cnt1;
        ans--;cnt--;
        flag=0;
        memset(num,0,sizeof(num));
        while(ans>1)
        {
            val=0;
            while(ans%sushu[cnt]==0)
            {
                val=1;
                num[flag]=sushu[cnt];
                ans/=sushu[cnt];     
                num[flag+1]++;                
            }         
            if(val==1)flag+=2;   
            cnt--;
        }
        for(i=0;i<flag;i++)printf("%d ",num[i]);
        printf("\n");
        memset(s,0,sizeof(s));              
    }    
    
    return 0;
}
