/*
ID: hjw00002
PROG: palsquare
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

int rev(int n,int b)
{
    int res=0;
    while(n)
    {
        res*=b;
        res+=(n%b);
        n/=b;        
    }    
    return res;
}

void change(int res,int n)
{
    char s[100];
    int k=0,tmp;
    while(res)
    {
        tmp=res%n;
        if(tmp>=10)s[k]=(char)(tmp-10+'A');
        else s[k]=(char)(tmp+'0');
        k++;
        res/=n;        
    }     
    for(int i=k-1;i>=0;i--)printf("%c",s[i]);
}

int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int n,i,sq,b;
    scanf("%d",&b);
    for(i=1;i<=300;i++)
    {
        sq=i*i;
        if(sq==rev(sq,b))
        {
            change(i,b);
            printf(" ");
            change(sq,b);
            printf("\n");                 
        }
    }
    
    //system("pause");
    return 0;
}
