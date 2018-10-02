#include<iostream>
using namespace std;

int main()
{
    int a1,b1,a2,b2,per1,per2;
    while(cin>>a1>>b1>>a2>>b2 && (a1!=0 || b1!=0 || a2!=0 || b2!=0))
    {
        if((a1>b1 && a2<b2) || (a1<b1 && a2>b2))swap(a1,b1);
        if(a1<=a2 && b1<=b2){cout<<"100%"<<endl;continue;}
        per1=a2*100/a1;
        per2=b2*100/b1;
        if(per1>per2)cout<<per2<<'%'<<endl;
        else cout<<per1<<'%'<<endl;
    }    
    
    system("pause");
    return 0;
}
