#include<iostream>
using namespace std;

int main()
{
    unsigned __int64 a,c,s;
    scanf("%I64u",&a);
    c=2*a+1;
    while((1+c*c)%(c-a)!=0)c--;
    s=(1+c*c)/(c-a);
    printf("%I64u",s);
    
    return 0;    
}
