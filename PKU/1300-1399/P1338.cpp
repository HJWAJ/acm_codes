#include<iostream>
#include<algorithm>
using namespace std;

long long int min(long long int a,long long int b,long long int c)
{
     long long int min=a;
     if(min>b)min=b;
     if(min>c)min=c;
     return min;
}

int main()
{
    int i=1,j=1,k=1,m=1;
    long long int p[1501];
    p[1]=1;
    for(m=2;m<=1500;m++)
    {
         p[m]=min(p[i]*2,p[j]*3,p[k]*5);
         if(p[m]==p[i]*2)i++; 
         if(p[m]==p[j]*3)j++; 
         if(p[m]==p[k]*5)k++;              
    }
    
    int n;
    while(cin>>n && n!=0)cout<<p[n]<<endl;
    
    system("pause");
    return 0;
}
