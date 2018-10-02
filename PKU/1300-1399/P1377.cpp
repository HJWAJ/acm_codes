#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int t,p,q,x,y,sub,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&p,&q);
        sub=0x7fffffff;
        cnt=0;
        for(x=1;x<=q;x++)
        {
            y=x*p/q;
            if(abs(y*q-x*p)<sub)
            {
                sub=abs(y*q-x*p);
                y++;
                cnt++;
                if(abs(y*q-x*p)<sub)sub=abs(y*q-x*p);
            }
            else
            {
                y++;
                if(abs(y*q-x*p)<sub)
                {
                    sub=abs(y*q-x*p);
                    cnt++;                
                } 
            }   
        }
        printf("%d\n",cnt);          
    }    
    
    return 0;
}
