#include<iostream>
using namespace std;

int main()
{
    int a,b,d,sum,i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        d=b-a;
        sum=0;
        i=j=1;
        while(sum<d)
        {
            sum+=i;
            j++;
            if(j%2==1)i++;           
        } 
        printf("%d\n",j-1);         
    }    
    
    system("pause");
    return 0;
}
