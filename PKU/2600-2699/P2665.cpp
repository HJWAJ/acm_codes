#include<iostream>
using namespace std;

int main()
{
    int l,m;
    while(cin>>l>>m && (l!=0 || m!=0))
    {
        l++;
        int a,b;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            l-=(b-a+1);    
        } 
        cout<<l<<endl;               
    }    
    
    system("pause");
    return 0;
}
