#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char dic[5][100],s[10000],dic2[3][100]={"beautiful","pretty","lovely"};
    int m,n,i,j,k,t,num,len,leng[5],leng2[3]={9,6,6};
    bool val;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        scanf("%s",dic[i]);
        leng[i]=strlen(dic[i]);
    }
    getchar();
    for(i=0;i<n;i++)
    {
        num=j=val=0;
        gets(s);
        len=strlen(s);
        s[0]=s[0]-'A'+'a';
        for(j=0;j<len;j++)
            if(s[j]=='!' && s[j+1]>='A' && s[j+1]<='Z')s[j+1]=s[j+1]-'A'+'a';
        for(j=0;j<len;j++)
            if((s[j]>='a' && s[j]<='z') && !(s[j+1]>='a' && s[j+1]<='z'))num++;
        for(t=0;t<m;t++)
        {
            for(j=0;j<len-leng[t]+1;j++)
            {
                for(k=0;k<leng[t];k++)
                    if(dic[t][k]!=s[j+k])break;
                if(k==leng[t] && ((j==0 || !(s[j-1]>='a' && s[j-1]<='z')) && !(s[j+k]>='a' && s[j+k]<='z')))
                {
                    if(val==0)printf("%s",dic[t]);
                    else printf(" %s",dic[t]);
                    val=1;
                    break;
                }
            }
        }
        if(val==0)printf("All");
        printf(": ");
        if(num<10)
        {
            printf("oh\n");
            continue;
        }
        for(t=0;t<3;t++)
        {
            for(j=0;j<len-leng2[t]+1;j++)
            {
                for(k=0;k<leng2[t];k++)
                    if(dic2[t][k]!=s[j+k])break;
                if(k==leng2[t])
                {
                    printf("xixi\n");
                    goto label;
                }
            }
        }
        if(t==3)printf("hehe\n");
        label:;
    }
        
    system("pause");
    return 0;
}
