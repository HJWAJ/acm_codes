#include<iostream>
#include<cstdlib>
using namespace std;
#define PI 3.1415927

int main()
{
    int r,i=1;
    float d,t,average,len;
    while(scanf("%f %d %f",&d,&r,&t),r)
    {
        len=PI*d*r/(12*5280); 
        average=(len*3600)/t;
        printf("Trip #%d: %.2f %.2f\n",i,len,average);
        i++;
    }
    
    system("pause");
    return 0;
}
