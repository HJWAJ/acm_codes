#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int w,b,ans;
    cin>>w>>b;
    if(w==b)ans=2*w;
    else if(w>b)ans=2*b+1;
    else ans=2*w+1;
    ans=int(sqrt(double(ans)));
    if(ans==0)cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    
    return 0;
}
