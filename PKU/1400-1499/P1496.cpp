#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int c(int n,int m)
{
    //if(m>n-m)m=n-m;
    int i,res=1;
    for(i=0;i<m;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

int main()
{
    char str[10];
    int i,j,k,l,len,res;
    //while(scanf("%d%d",&i,&j)!=EOF)printf("%d\n",c(i,j));
    while(scanf("%s",str)!=EOF)
    {
        len=strlen(str);
        for(i=0;i<len;i++)
            for(k=i+1;k<len;k++)
		       if(str[i]>=str[k])
               {
                   puts("0");
                   goto label;
               }
        res=0;
        for(j=1;j<=i;j++)res+=c(26,j);
        for(l=0;str[l]!=0;l++)res-=c(26-(str[l]-'a'+1),i-l);
        printf("%d\n",res);
        label:;
    }
    
    return 0;
}
