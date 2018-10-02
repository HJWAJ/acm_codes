#include<iostream>
using namespace std;

int main()
{
    int num,root,ex,i,p,cnt;
    char s;
    while(cin>>root>>s>>ex && (root!=0 || ex!=0))
    {
        num=root;
        for(i=0;i<ex;i++)num*=10;
        p=1;
        while(p<=num)p*=2;
        num=num-p/2;
        cnt=1+2*num;
        cout<<cnt<<endl;            
    }    
    
    system("pause");
    return 0;
}
