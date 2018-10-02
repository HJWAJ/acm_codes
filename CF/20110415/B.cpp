#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int l,x,y,flag,len,i,ii;
    char str[10],s[205],ch;
    scanf("%d%d%d%s%s%s",&l,&x,&y,str,str,s);
    if(x==y){printf("Controller 0\n");goto label;}
    if(l<3)
    {
        len=strlen(s);
        for(i=0;i<len;i++)if(s[i]=='1')continue;
        printf("Controller %d\n",i);goto label;
    }
    len=strlen(s);
    ch=s[0];
    if(str[0]=='h')flag=1;
    else flag=2;
    if(ch=='0')
    {
        for(i=0;i<len;i++)
            if(s[i]!=ch)break;
        i++;
        if(x>y)
        {
            x+=i;
            if(x>l)x=l;
            if(str[0]=='h')
            {
                flag=1;
                if(y-1>i)y-=i;
                else
                {
                    ii=i;
                    i++;i-=y;
                    y=i+1;
                    if(y>=x)
                    {
                        if(y<l){printf("Controller %d\n",ii);goto label;}
                        else {printf("Controller %d\n",ii-(y-l));goto label;}        
                    }    
                    i=ii;
                    flag=2;
                }             
            } 
            if(str[0]=='t')
            {
                flag=2;
                y+=i;
                if(y>l)y=l;
                if(y>=x)
                {
                    if(y<l){printf("Controller %d\n",ii);goto label;}
                    else {printf("Controller %d\n",ii-(y-l));goto label;}        
                }
            }               
        }
        if(x<y)
        {
            x-=i;
            if(x<1)x=1;
            if(str[0]=='t')
            {
                flag=2;
                if(y+i<=l)y+=i;
                else
                {
                    flag=1;
                    ii=i;
                    i-=(l-y);
                    y=l-i;
                    if(y<=x)
                    {
                        if(y>1){printf("Controller %d\n",ii);goto label;}
                        else {printf("Controller %d\n",ii-y+1);goto label;}        
                    }    
                    i=ii;
                }             
            } 
            if(str[0]=='h')
            {
                flag=1;
                y-=i;
                if(y<1)y=1;
                if(y<=x)
                {
                    if(y>1){printf("Controller %d\n",ii);goto label;}
                    else {printf("Controller %d\n",ii-y+1);goto label;}        
                }
            }               
        }           
    }
    for(;i<len;i++)
    {
        ii=i;
        while(s[i]=='1')i++;
        ii=i-ii;
        if(flag=1)
        {
            if(ii<y-1)y-=ii;
            else
            {
                ii-=(y-1);
                y=1;
                flag=2;
                ii%=(2*l-2);
                if(ii<l-1)y+=ii;
                else
                {
                    ii-=(l-1);
                    y=l;
                    y-=ii;
                    flag=1;    
                }    
            }      
        }
        else
        {
            if(ii<l-y)y+=ii;
            else
            {
                ii-=(l-y);
                y=l;
                flag=1;
                ii%=(2*l-2);
                if(ii<l-1)y-=ii;
                else
                {
                    ii-=(l-1);
                    y=1;
                    y+=ii;
                    flag=2;    
                }    
            }
        }
        ii=i;
        while(s[i]=='0')i++;
        ii=i-ii;
        if(flag==1)
        {
            if(y==l)
            {
                x=1;
                if(ii>=l-1){printf("Controller %d\n",i-(ii-l+1));goto label;}        
            }
            else
            {
                x=l;
                if(ii>=y-1+l-1){printf("Controller %d\n",i-(ii-(y-1+l-1)));goto label;}    
            }           
        }
        if(flag==2)
        {
            if(y==1)
            {
                x=l;
                if(ii>=l-1){printf("Controller %d\n",i-ii-(l-1));goto label;}        
            }
            else
            {
                x=1;
                if(ii>=l-y+l-1){printf("Controller %d\n",i-(ii-(l-y+l-1)));goto label;}    
            }           
        }               
    }
    printf("Stowaway\n");
        
    label:;
    //system("pause");
    return 0;
}
