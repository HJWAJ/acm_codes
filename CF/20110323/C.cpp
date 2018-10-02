#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct basic
{
    char s[105];
    int num[105];       
}bas[105];

struct compo
{
    char s[105];  
    basic thing[50];
    int num;  
}comp[105];

struct gething
{
    char s[105];
    int num;   
}got[105];

int cmp(const void *p,const void *q)
{
    gething *a=(gething *)p;
    gething *b=(gething *)q;
    return strcmp(a->s,b->s);    
}

int main()
{
    int k,n,m,q,i,j,ii,jj,tmpnum,numb,min,flag;
    char tmp,temp[5005];
    scanf("%d%d%d%d",&k,&n,&m,&q);
    memset(bas,0,sizeof(bas));
    memset(comp,0,sizeof(comp));
    memset(got,0,sizeof(got));
    for(i=0;i<n;i++)
    {
        scanf("%s",bas[i].s);
        for(j=0;j<105;j++)bas[i].num[j]=0;
    }
    for(i=0;i<m;i++)
    {
        getchar();
        j=0;
        while(scanf("%c",&tmp) && tmp!=':')comp[i].s[j++]=tmp;
        j=0;
        while(1)
        {
            scanf("%s%d%c",comp[i].thing[j].s,&comp[i].thing[j].num[0],&tmp);
            if(tmp!=',')break;
            j++;
        }
        numb=j+1;                
    }
    for(i=0;i<q;i++)
    {
        scanf("%d%s",&tmpnum,temp);
        for(j=0;j<n;j++)
            if(strcmp(temp,bas[j].s)==0)
            {
                bas[j].num[tmpnum]++;
                break;
            }                
    }
    for(i=0;i<k;i++)
    {
        flag=0;
        for(j=0;j<m;j++)
        {
            min=999999;
            for(ii=0;ii<comp[j].num;ii++)
            {
                for(jj=0;jj<n;jj++)
                    if(strcmp(comp[j].thing[ii].s,bas[jj].s)==0)
                    {
                        numb=bas[jj].num[k-1]/comp[j].thing[ii].num[0];
                        if(numb<min)min=numb;break;                                            
                    }
            }
            if(min)
            {
                strcpy(got[flag].s,comp[j].s);
                got[flag].num=min;
                flag++;       
            }                
        }
        min=0;
        for(j=0;j<flag;j++)min+=got[j].num;
        printf("%d\n",min);
        if(min)
        {
            qsort(got,flag,sizeof(got[0]),cmp);
            for(j=0;j<flag;j++)
                printf("%s %d\n",got[j].s,got[j].num);
        }                
    }
    
    system("pause");
    return 0;
}
