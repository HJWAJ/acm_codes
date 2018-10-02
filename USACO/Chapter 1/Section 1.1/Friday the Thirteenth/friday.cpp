/*
ID: hjw00002
PROG: friday
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

bool isleap(int n)
{
    n+=1900;
    if((!(n%4) && n%100) || !(n%400))return 1;
    return 0;     
}

int main()
{
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    
    int week[7];
    memset(week,0,sizeof(week));
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leapmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    
    int n,i,j,day=13;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<12;j++)
        {
            week[day%=7]++;
            if(isleap(i))day+=leapmonth[j];
            else day+=month[j];
        }
    }
    printf("%d",week[6]);
    for(i=0;i<6;i++)printf(" %d",week[i]);
    printf("\n");
    
    //system("pause");
    return 0;
}
