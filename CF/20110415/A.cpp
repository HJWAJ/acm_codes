#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    char s[105],maxs[105];
    int su,usu,a,b,c,d,e,n,score,max;
    scanf("%d",&n);
    max=-99999999;
    while(n--)
    {
        scanf("%s%d%d%d%d%d%d%d",s,&su,&usu,&a,&b,&c,&d,&e);
        score=su*100-usu*50+a+b+c+d+e;
        if(max<score)
        {
            max=score;
            strcpy(maxs,s);
        }
    }
    printf("%s\n",maxs);
    
    //system("pause");
    return 0;
}
