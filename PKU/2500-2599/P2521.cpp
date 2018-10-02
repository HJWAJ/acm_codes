#include<iostream>
using namespace std;

int main()
{
    int n,m,p,c,s;
    cin>>n>>m>>p>>c;
    while(n!=0||m!=0||p!=0||c!=0)
    {
        s=0-(m-n-p);
        cout<<s<<endl;
        cin>>n>>m>>p>>c;                             
    }
    
    system("pause");
    return 0;    
}
