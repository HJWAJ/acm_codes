#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct stri
{
    char s[30];
}str[20000];

int cmp(const void *p1,const void *p2)
{
    return strcmp( ((stri *)p1)->s , ((stri *)p2)->s );
}

int main()
{
    int n,len,i,cnt[20001],num,flag;
    while(scanf("%d%d",&n,&len) && !(n==0 && len==0))
    {
        for(i=0;i<n;i++)scanf("%s",str[i].s);
        memset(cnt,0,sizeof(cnt));
        qsort(str,n,30,cmp);
        //for(i=0;i<n;i++)printf("%s\n",str[i].s);
        i=1;
        num=0;
        flag=0;
        while(i<n)
        {
            if(strcmp(str[flag].s,str[i].s)==0)num++;
            else
            {
                cnt[num]++;
                num=0;
                flag=i;
            }
            i++;
        }
        cnt[num]++;
        for(i=0;i<n;i++)printf("%d\n",cnt[i]);
    }    
    
    //system("pause");
    return 0;
}
