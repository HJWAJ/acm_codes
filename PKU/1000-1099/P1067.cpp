#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
    
        int temp;
        if(a>b)
        {temp=a;a=b;b=temp;}
        if((a==int(int(a*(sqrt(5.0)-1)/2.0)*(sqrt(5.0)+1)/2.0)  &&  (b==a+int(a*(sqrt(5.0)-1)/2.0)) ) || ( a==int(int((sqrt(5.0)-1)/2.0*a+1)*(sqrt(5.0)+1)/2.0)  &&(b==a+int(a*(sqrt(5.0)-1)/2.0)+1 )))  cout<<"0"<<endl;
        else cout<<"1"<<endl;  
    }
    system("pause");
    return 0;
}
