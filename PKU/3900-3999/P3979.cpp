#include<iostream>
#include<cstdio>
using namespace std;

void swap(int &a,int &b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;     
}

int gcd(int a,int b)
{
    if(a<b)swap(a,b);
    while(b!=0)
    {
        a%=b;
        swap(a,b);           
    }
    return a;    
}

int main()
{
    char s[10];
    int a,b,c,d,fenzi,fenmu,gcds;
    memset(s,0,sizeof(s));
    while(scanf("%s",s)!=EOF)
    {
        a=s[0]-'0';
        b=s[2]-'0';
        c=s[4]-'0';
        d=s[6]-'0';
        if(s[3]=='+')fenzi=a*d+b*c;
        else fenzi=a*d-b*c;
        fenmu=b*d;
        if(fenzi==0)
        {
            printf("0\n");
            continue;
        }
        if(fenzi<0)
        {
            printf("-");
            fenzi=0-fenzi;           
        }
        gcds=gcd(fenzi,fenmu);
        fenzi/=gcds;
        fenmu/=gcds;
        if(fenmu==1)printf("%d\n",fenzi);
        else printf("%d/%d\n",fenzi,fenmu);
        memset(s,0,sizeof(s));                 
    }
    
    system("pause");
    return 0;
}
