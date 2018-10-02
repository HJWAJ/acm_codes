#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void myset(int val[12][17],char s[12][17])
{
    int i,j;
    for(i=1;i<=10;i++)
        for(j=1;j<=15;j++)
            if(s[i][j]=='0')val[i][j]=-1;
            else val[i][j]=0;     
}

bool canoper(char s[12][17])
{
    int i,j;
    for(i=1;i<=10;i++)
        for(j=1;j<=15;j++)
            if((s[i][j]==s[i][j+1] && j<15) || (s[i][j]==s[i+1][j] && i<10))return 1;
    return 0;     
}

void dfs(int i,int j,char s[12][17],int val[12][17],int num)
{
    val[i][j]=num;
    if(s[i][j-1]==s[i][j] && val[i][j-1]==0)
    {
        //val[i][j-1]=num;
        dfs(i,j-1,s,val,num);                      
    }
    if(s[i][j+1]==s[i][j] && val[i][j+1]==0)
    {
        //val[i][j+1]=num;
        dfs(i,j+1,s,val,num);                      
    }
    if(s[i-1][j]==s[i][j] && val[i-1][j]==0)
    {
        //val[i-1][j]=num;
        dfs(i-1,j,s,val,num);                      
    }
    if(s[i+1][j]==s[i][j] && val[i+1][j]==0)
    {
        //val[i+1][j]=num;
        dfs(i+1,j,s,val,num);                      
    }
}

void move(char s[12][17],int j)
{
    int flagb,flagt;
    flagb=flagt=1;
    while(flagt<=10)
    {
        while(s[flagb][j]!='0')
        {
            flagb++;
            if(flagb>10)return;
        }
        flagt++;
        if(flagt>10)break;
        if(flagt>flagb && s[flagt][j]!='0')
        {
            s[flagb][j]=s[flagt][j];
            flagb++;
            s[flagt][j]='0';               
        }                
    }     
}

void colmove(char s[12][17])
{
    int i,flagl,flagr;
    flagl=flagr=1;
    while(flagr<=15)
    {
        while(s[1][flagl]!='0')
        {
            flagl++;
            if(flagl>15)return;
        }
        flagr++;
        if(flagr>15)break;
        if(flagr>flagl && s[1][flagr]!='0')
        {
            for(i=1;i<=10;i++)
            {
                s[i][flagl]=s[i][flagr];
                s[i][flagr]='0';
            }
            flagl++;               
        }                
    }     
}

int oper(char s[12][17],int val[12][17],int maxnum,int movenum)
{
    int i,j,res=0,flag=0,x,y,score;
    char ch;
    bool valued=0;
    for(i=1;i<=15;i++)
        for(j=1;j<=10;j++)
            if(val[j][i]==maxnum)
            {
                ch=s[j][i];
                if(valued==0)
                {
                    x=j;
                    y=i;             
                }
                valued=1;
                res++;
                s[j][i]='0';                     
            }
    if(res==0)return -1;
    for(j=1;j<=15;j++)move(s,j);
    colmove(s);
    score=(res-2)*(res-2);
    printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",movenum,x,y,res,ch,score);
    return score;
}

int main()
{
    char s[12][17];
    int t,tt=0,i,j,cnt[150],num,max,score,getscore,movenum,maxnum;
    scanf("%d",&t);
    int val[12][17];
    while(t--)
    {
        tt++;
        printf("Game %d:\n\n",tt);
        memset(s,0,sizeof(s));
        memset(val,0,sizeof(val));
        for(i=1;i<=10;i++)
        {
            scanf("%s",s[11-i]);
            for(j=15;j>=1;j--)s[11-i][j]=s[11-i][j-1];
            s[11-i][0]='0';
        }
        movenum=score=0;
        while(canoper(s))
        {
            myset(val,s);
            //memset(val,0,sizeof(val));
            memset(cnt,0,sizeof(cnt));
            num=1;
            for(i=1;i<=10;i++)
                for(j=1;j<=15;j++)
                    if(val[i][j]==0)
                    {
                        dfs(i,j,s,val,num);
                        num++;
                    }
            for(i=1;i<=10;i++)
                for(j=1;j<=15;j++)
                    if(val[i][j]!=0)cnt[val[i][j]]++;
            max=0;
            for(i=1;i<num;i++)
            {
                if(max<cnt[i])
                {
                    max=cnt[i];
                    maxnum=i;
                }
            }
            movenum++;
            if(max>1)
            {
                getscore=oper(s,val,maxnum,movenum);
                if(getscore!=-1)score+=getscore;
                else goto label;
            }
        }
        label:num=0;
        for(i=1;i<=10;i++)
            for(j=1;j<=15;j++)
                if(s[i][j]!='0')num++;
        if(num==0)score+=1000;
        printf("Final score: %d, with %d balls remaining.\n",score,num);
    }
    
    system("pause");
    return 0;
}
