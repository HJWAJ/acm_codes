#include<iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        int m=n;
        int i=1;
        while(n-i>0)
        {
            n-=i;
            i++;             
        }       
        n=m;
        if(i%2==1)
        {
            n=n-i*(i-1)/2;
            n=i-n+1;
            i=i-n+1;
            cout<<"TERM "<<m<<" IS "<<n<<"/"<<i<<endl;          
        }
        else
        {
            n=n-i*(i-1)/2;
            n=i-n+1;
            i=i-n+1;
            cout<<"TERM "<<m<<" IS "<<i<<"/"<<n<<endl;   
        }     
        
    }
    
    system("pause");
    return 0;
}
