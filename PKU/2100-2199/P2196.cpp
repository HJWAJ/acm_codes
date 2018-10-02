#include<iostream>
using namespace std;

int main()
{
    int i,s1,s2,s3,n;
    for(i=2992;i<10000;i++)
    {
        n=i;
        s1=s2=s3=0;
        
        s1=s1+i%10;
        i/=10;
        s1=s1+i%10;
        i/=10;
        s1=s1+i%10;
        s1=s1+i/10;
        i=n; 
        
        s2=s2+i%12;
        i/=12;
        s2=s2+i%12;
        i/=12;
        s2=s2+i%12;
        s2=s2+i/12;
        i=n;
        
        s3=s3+i%16;
        i/=16;
        s3=s3+i%16;
        i/=16;
        s3=s3+i%16;
        s3=s3+i/16;
        i=n;
        
        if(s1==s2 && s2==s3)cout<<n<<endl;        
    }    
    
    system("pause");
    return 0;
}
