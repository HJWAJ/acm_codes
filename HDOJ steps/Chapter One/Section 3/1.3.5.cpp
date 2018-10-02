#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    char name[15];
    int num;
    int penalty;
}stu[10050];
char penaltytime[20];
int cmp(const void *p,const void *q)
{
    node *a=(node *)p;
    node *b=(node *)q;
    if(a->num!=b->num)return b->num - a->num;
    if(a->penalty!=b->penalty)return a->penalty-b->penalty;
    return strcmp(a->name,b->name);
}
int main()
{
    int m,n,num=0,i,j,len,tmp;
    scanf("%d%d",&n,&m);
    while(scanf("%s",stu[num].name)!=EOF)
    {
        stu[num].num=stu[num].penalty=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",penaltytime);
            if(penaltytime[0]!='-' && penaltytime[0]!='0')
            {
                stu[num].num++;
                len=strlen(penaltytime);
                tmp=0;
                for(j=0;j<len;j++)
                {
                    if(penaltytime[j]=='(')
                    {
                        stu[num].penalty+=tmp;
                        tmp=0;
                        break;
                    }
                    else
                    {
                        tmp*=10;
                        tmp+=penaltytime[j]-'0';
                    }
                }
                j++;
                if(tmp!=0)
                {
                    stu[num].penalty+=tmp;
                    tmp=0;
                }
                for(;j<len;j++)
                {
                    if(penaltytime[j]==')')
                    {
                        stu[num].penalty+=tmp*m;
                        break;
                    }
                    else
                    {
                        tmp*=10;
                        tmp+=penaltytime[j]-'0';
                    }
                }
            }
        }
        num++;
    }
    qsort(stu,num,sizeof(stu[0]),cmp);
    for(i=0;i<num;i++)
    {
        printf("%s",stu[i].name);
        for(j=strlen(stu[i].name);j<11;j++)printf(" ");
        if(stu[i].num>=10)printf("%d ",stu[i].num);
        else printf(" %d ",stu[i].num);
        if(stu[i].penalty>=1000)printf("%d\n",stu[i].penalty);
        else if(stu[i].penalty>=100)printf(" %d\n",stu[i].penalty);
        else if(stu[i].penalty>=10)printf("  %d\n",stu[i].penalty);
        else printf("   %d\n",stu[i].penalty);
    }
    return 0;
}
