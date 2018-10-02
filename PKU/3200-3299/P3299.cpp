#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main()
{
    double temperature,dewpoint,humidex;
    double h,e,f1,f2;
    char c1[2],c2[2];
    while(scanf("%s",c1) && c1[0]!='E')
    {
        scanf("%lf%s%lf",&f1,c2,&f2);
        if(c1[0]=='T' && c2[0]=='D')
        {
            temperature = (c1[0]=='T') ? f1:f2;
            dewpoint = (c1[0]=='D') ? f1:f2;
            e = (double) (6.11 * exp (5417.7530 * ((1/273.16) - (1/(dewpoint+273.16)))));
            h = (double) ((0.5555) * (e - 10.0));
            humidex = temperature + h;
        }
        else if(c1[0]=='T' && c2[0]=='H')
        {
            temperature = c1[0]=='T' ? f1:f2;
            humidex = (c1[0]=='H') ? f1:f2;
            h = humidex - temperature;
            e = (double) (h / 0.5555 + 10.0) ;
            dewpoint = (double) (1/(-log(e/6.11)/5417.7530 + (1/273.16))-273.16);
        }
        else if(c1[0]=='H' && c2[0]=='D')
        {
            humidex = (c1[0]=='H') ? f1:f2;
            dewpoint = (c1[0]=='D') ? f1:f2;
            e = (double) (6.11 * exp (5417.7530 * ((1/273.16) - (1/(dewpoint+273.16)))));
            h = (double) ((0.5555) * (e - 10.0));
            temperature = humidex - h;
        }
        printf("T %.1f D %.1f H %.1f\n",temperature,dewpoint,humidex);
    }
    return 0;
}
