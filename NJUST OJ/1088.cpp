#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long int a[100005];

int main()
{
    //freopen("1.txt","w",stdout);
    long long int i,j,flag=1,tmp,t,n;
    bool val[10001];
    memset(val,0,sizeof(val));
    memset(a,0,sizeof(a));
    a[0]=1;
    //system("pause");
    for(i=2;i<=10000;i++)
    {
        if(val[i]==0)
        {
            tmp=i;
            while(1)
            {
                tmp*=i;
                if(tmp<=10000)val[tmp]=1;
                if(tmp<=100000000)a[flag++]=tmp;
                else break;
            }
        }
        //system("pause");
    }
    //for(i=0;i<flag;i++)cout<<a[i]<<endl;
    sort(a,a+flag);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        i=0;
        while(a[i]<=n && i<flag)i++;
        printf("%lld\n",i);          
    }    
    
    //system("pause");
    return 0;
}
