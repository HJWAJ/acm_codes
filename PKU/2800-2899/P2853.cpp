#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    int t,num,n,nn,i,cnt;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d%d",&num,&n);
        if(n&1)cnt++;
        nn=int(sqrt(double(n)));
        if(nn*nn==n && (nn&1))cnt--;
        for(i=2;i<=nn;i++)
            if(n%i==0)
            {
                if(i&1)cnt++;
                if((n/i)&1)cnt++;          
            }
        printf("%d %d\n",num,cnt);
    }    
    
    return 0;
}
