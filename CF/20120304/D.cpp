#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int n,num;
int a[20005];
int divv[505];
int sum,maxx=-20000005;
int divvide(int n)
{
    int i,flag=0;
    double sq=sqrt(double(n));
    for(i=1;i<sq;i++)
        if(n%i==0)
        {
            divv[flag++]=i;
            divv[flag++]=n/i;
        }
    if(sq*sq==n && sq==floor(sq))divv[flag++]=sq;
    return flag;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",a+i);
    num=divvide(n);
    //for(i=0;i<num;i++)cout<<divv[i]<<' ';
    //cout<<endl<<endl;
    for(i=0;i<num;i++)
    {
        if(divv[i]==n || double(divv[i])==n/2.0)continue;
        //cout<<"   "<<divv[i]<<endl;
        for(j=0;j<divv[i];j++)
        {
            sum=0;
            for(k=0;k<n;k+=divv[i])
                sum+=a[j+k];
            //cout<<sum<<endl;
            if(sum>maxx)maxx=sum;
        }
    }
    printf("%d\n",maxx);
    return 0;
}
