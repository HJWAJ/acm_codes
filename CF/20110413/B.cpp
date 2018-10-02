#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

struct nod
{
    char name[105];
    int cnt;       
}node[1005];

int query(char s[],int num)
{
    int i;
    for(i=0;i<num;i++)
        if(strcmp(s,node[i].name)==0)
            return i;
    return -1;    
}

int cmp(const void *p,const void *q)
{
    nod *a=(nod *)p;
    nod *b=(nod *)q;
    if(a->cnt == b->cnt)return strcmp(a->name,b->name);
    return b->cnt - a->cnt;    
}

int main()
{
    char s[105],tmp[105];
    int n,flag,flag1,num=0,len,i;
    bool val;
    memset(node,0,sizeof(node));
    memset(s,0,sizeof(s));
    scanf("%s%d",s,&n);
    while(n--)
    {
        scanf("%s",tmp);
        val=0;
        if(strcmp(tmp,s))
        {
            flag=query(tmp,num);
            if(flag==-1)
            {
                flag=num;
                strcpy(node[num].name,tmp);
                num++;            
            }
        }
        else val=1;
        scanf("%s",tmp);
        if(strcmp(tmp,"posted")==0)
        {
            scanf("%s",tmp);
            scanf("%s",tmp);
            len=strlen(tmp);
            tmp[len-2]='\0';
            if(val==0 && strcmp(tmp,s)==0)node[flag].cnt+=15;
            if(strcmp(tmp,s))
            {
                flag1=query(tmp,num);
                if(flag1==-1)
                {
                    flag1=num;
                    strcpy(node[num].name,tmp);
                    num++;            
                }
                if(val)node[flag1].cnt+=15;
            }               
        }
        else if(strcmp(tmp,"commented")==0)
        {
            scanf("%s",tmp);
            scanf("%s",tmp);
            len=strlen(tmp);
            tmp[len-2]='\0';
            if(val==0 && strcmp(tmp,s)==0)node[flag].cnt+=10;
            if(strcmp(tmp,s))
            {
                flag1=query(tmp,num);
                if(flag1==-1)
                {
                    flag1=num;
                    strcpy(node[num].name,tmp);
                    num++;            
                }
                if(val)node[flag1].cnt+=10;
            }
        }
        else
        {
            scanf("%s",tmp);
            len=strlen(tmp);
            tmp[len-2]='\0';
            if(val==0 && strcmp(tmp,s)==0)node[flag].cnt+=5;
            if(strcmp(tmp,s))
            {
                flag1=query(tmp,num);
                if(flag1==-1)
                {
                    flag1=num;
                    strcpy(node[num].name,tmp);
                    num++;            
                }
                if(val)node[flag1].cnt+=5;
            }
        }
        scanf("%s",tmp);
    }
    qsort(node,num,sizeof(node[0]),cmp);
    for(i=0;i<num;i++)printf("%s\n",node[i].name);
    
    //system("pause");   
    return 0;
}
