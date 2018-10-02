#include<iostream>
using namespace std;

int main()
{
    int f[6];
    float a,b,c;
    while(scanf("%d%d%d",&f[0],&f[1],&f[2])!=EOF)
    {
        a=(f[2]-2*f[1]+f[0])/2.0;
        b=(-f[0])-(f[2]+f[0])/2.0+2*f[1];
        c=f[0];            
        f[3]=9*a+3*b+c;
        f[4]=16*a+4*b+c;
        f[5]=25*a+5*b+c;
        printf("%d %d %d\n",f[3],f[4],f[5]);                  
    }    
    
    system("pause");
    return 0;
}
