#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int n,i,a[50];
    char s[10][100]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
    a[0]=1;
    for(i=1;a[i-1]<1000000000;i++)
        a[i]=a[i-1]*2;
    scanf("%d",&n);
    for(i=0;;i++)
    {
        if(n>5*a[i])n-=5*a[i];
        else
        {
            if(n<=a[i])printf("%s\n",s[0]);
            else if(n<=2*a[i])printf("%s\n",s[1]);
            else if(n<=3*a[i])printf("%s\n",s[2]);
            else if(n<=4*a[i])printf("%s\n",s[3]);
            else if(n<=5*a[i])printf("%s\n",s[4]);
            break;    
        }            
    }
        
    //while(1);
    return 0;
}
