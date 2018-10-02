#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 2000000005
using namespace std;

int main()
{
    __int64 a[100005],n,tmp,flag=0,i,j,sum;
    char s[10];
    scanf("%I64d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        if(s[0]=='a')
        {
            //printf("1\n");
            scanf("%I64d",&tmp);
            a[flag]=tmp;flag++;
        }
        else if(s[0]=='d')
        {
            //printf("2\n");
            scanf("%I64d",&tmp);
            nth_element(a,a+tmp-1,a+flag);
            a[tmp-1]=MAX;     
        }                
        else
        {
            sort(a,a+flag);
            sum=0;
            for(j=2;j<flag;j+=5)sum+=a[j];
            printf("%I64d\n",sum);    
        }
    }
    
    while(1);    
    return 0;
}
