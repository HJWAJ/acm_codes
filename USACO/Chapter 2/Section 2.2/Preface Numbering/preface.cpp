/*
ID: hjw00002
PROG: preface
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main()
{    
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    int n,i,tmp,I,V,X,L,C,D,M;
    scanf("%d",&n);
    I=V=X=L=C=D=M=0;
    for(i=1;i<=n;i++)
    {
        tmp=i;
        if(tmp>=1000)
        {
            M+=(tmp/1000);
            tmp%=1000;            
        }
        if(tmp>=500)
        {
            if(tmp>=900)
            {
                M++;C++;
                tmp-=900;            
            }
            else
            {
                D++;
                tmp-=500;
            }            
        }
        if(tmp>=100)
        {
            if(tmp>=400)
            {
                D++;C++;
                tmp-=400;            
            }
            else
            {
                C+=(tmp/100);
                tmp%=100;    
            }            
        }
        if(tmp>=50)
        {
            if(tmp>=90)
            {
                C++;X++;
                tmp-=90;           
            }
            else
            {
                L++;
                tmp-=50;
            }           
        }
        if(tmp>=10)
        {
            if(tmp>=40)
            {
                L++;X++;
                tmp-=40;            
            }
            else
            {
                X+=(tmp/10);
                tmp%=10;    
            }            
        }
        if(tmp>=5)
        {
            if(tmp==9)
            {
                X++;I++;
                tmp=0;         
            }
            else
            {
                V++;
                tmp-=5;
            }          
        }
        if(tmp==4)
        {
            V++;I++;          
        }
        else
        {
            I+=tmp;    
        }                
    }
    printf("I %d\n",I);
    if(!V && !X && !L && !C && !D && !M)goto label;
    printf("V %d\n",V);
    if(!X && !L && !C && !D && !M)goto label;
    printf("X %d\n",X);
    if(!L && !C && !D && !M)goto label;
    printf("L %d\n",L);
    if(!C && !D && !M)goto label;
    printf("C %d\n",C);
    if(!D && !M)goto label;
    printf("D %d\n",D);
    if(!M)goto label;
    printf("M %d\n",M);
    label:;
    
    //system("pause");
    return 0;
}
