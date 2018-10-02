#include<iostream>
using namespace std;

int main()
{
    int n,num,i,count,p;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>num;
        count=0;
        p=5;
        while(num>=p)
        {
            count=count+num/p;
            p*=5;
        }        
        cout<<count<<endl;                   
    }    
    
    system("pause");
    return 0;
}
