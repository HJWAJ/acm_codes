#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int x,y,n=0;
    scanf("%d%d",&x,&y);
    while(1)
    {
        if(x>1 && y>1)
        {
            x-=2;
            y-=2;       
        }        
        else if(x==1 && y>=12)
        {
            x=0;
            y-=12;     
        }         
        else if(y>=22)
        {
            y-=22;    
        }
        else {printf("Hanako\n");break;}
        if(y>=22)y-=22;
        else if(x>0 && y>=12)
        {
            x--;
            y-=12;     
        }
        else if(x>1 && y>=2)
        {
            x-=2;
            y-=2;     
        }
        else {printf("Ciel\n");break;}
    }
    
    //system("pause");    
    return 0;
}
