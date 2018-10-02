#include<iostream>
using namespace std;

int main()
{
    int t,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        printf("%.3lf\n",(m+n+10)/7.0);          
    }    
    
    return 0;
}
