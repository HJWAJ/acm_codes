#include<iostream>
using namespace std;

int main()
{
    float a[12],s;
    for(int i=0;i<12;i++)
       {
           cin>>a[i];
           s+=a[i];     
       }
    cout<<"$"<<float(int(s*100/12+0.5))/100;
    
    system("pause");
    return 0;
    }
