#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int n,m,s,f,t;
    scanf("%d%d",&n,&m);
    while(n--)
    {
        scanf("%d%d%d",&s,&f,&t);
        if(s==f)
        {
            printf("%d\n",t);
            continue;
        }
        else if(s<f)
        {
            if(t%(2*(m-1))+1>s)t=(t/(2*(m-1))+1)*2*(m-1);
            else t=t/(2*(m-1))*2*(m-1);
            t+=(f-1);
        }
        else if(s>f)
        {
            if(t%(2*(m-1))>m-1+(m-s))t=(t/(2*(m-1))+1)*2*(m-1);
            else t=t/(2*(m-1))*2*(m-1);
            t+=(2*m-1-f);
        }
        printf("%d\n",t);
    }
    return 0;
}
