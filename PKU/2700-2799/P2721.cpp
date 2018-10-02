#include<iostream>
using namespace std;

long long int c(int a,int b)
{
    int i;
    long long int s=1;
    for(i=1;i<=a;i++)s=s*(b-i+1)/i;
    return s;    
}

int main()
{
    int a,b;
    while(cin>>a>>b && (a!=-1 ||b!=-1))
    {
        int num=a+b;
        long long int s=c(num,26);
        long long int s0=c(a,13);  
        long long int s1=c(b,13); 
        double p; 
        p=double(s0)*double(s1)/double(s);
        if(a!=b)p*=2.0; 
        printf("%d-%d split: %.8lf\n",a,b,p);             
    }    
    
    system("pause");
    return 0;
}
