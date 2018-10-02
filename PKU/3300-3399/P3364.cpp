#include<iostream>
using namespace std;

int main()
{
    int m,n,c,ans;
    while(cin>>m>>n>>c && !(m==0 && n==0 && c==0))printf("%d\n",((m-7)*(n-7)+c)/2);
    
    return 0;
}
