#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int i;
    int num;
    char s[100];
    double d;
    while(scanf("%d%s%lf",&num,s,&d)!=EOF)
    {
        scanf("%d%s%lf",&num,s,&d);
        printf("%d%s%lf\n",num,s,d);
        printf("\"%c",s[0]);
        if('a'<=s[1] && s[1]<='z')printf("%c\",",s[1]);
        else printf("\",");
    }
    
    //system("pause");
    return 0;
}
