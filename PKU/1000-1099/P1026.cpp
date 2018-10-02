#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,a[205],k,i,j,len,nn,tmp,f,r;
    bool bo[205];
    char s[205],ss[205];
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            a[i]--;
        }
        while(scanf("%d",&k) && k)
        {
            memset(s,0,sizeof(s));
            memset(ss,0,sizeof(ss));
            memset(bo,0,sizeof(bo));
            getchar();
            gets(s);
            len=strlen(s);
            if(len<n)
                for(i=len;i<n;i++)s[i]=' ';
            for(i=0;i<n;i++)
            {
                j=i;
                f=0;
                if(bo[j])continue;
                while(!bo[j])
                {
                    bo[j]=1;
                    j=a[j];
                    f++;
                }
                if(f==1)ss[i]=s[i];
                if(k%f==0)
                {
                    tmp=i;
                    for(j=0;j<f;j++)
                    {
                        ss[tmp]=s[tmp];
                        tmp=a[tmp];
                    }
                }
                for(r=0;r<k%f;r++)
                {
                    tmp=i;
                    for(j=0;j<f;j++)
                    {
                        ss[a[tmp]]=s[tmp];
                        tmp=a[tmp];
                    }
                    tmp=i;
                    for(j=0;j<f;j++)
                    {
                        s[tmp]=ss[tmp];
                        tmp=a[tmp];
                    }
                }
            }
            printf("%s\n",ss);
        }
        printf("\n");
    }
    return 0;
}
