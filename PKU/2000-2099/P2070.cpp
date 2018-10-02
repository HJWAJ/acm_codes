#include<iostream>
using namespace std;

struct stdqua
{
    double ss,mw,ms;
}w,l,q;

int main()
{
    w.ss=4.5;w.mw=150;w.ms=200;
    l.ss=6.0;l.mw=300;l.ms=500;    
    q.ss=5.0;q.mw=200;q.ms=300;
    double sp,we,st;
    bool val;
    while(cin>>sp>>we>>st && (sp!=0||we!=0||st!=0))
    {
        val=0;
        if(sp<=w.ss && we>=w.mw && st>=w.ms){val=1;cout<<"Wide Receiver ";}
        if(sp<=l.ss && we>=l.mw && st>=l.ms){val=1;cout<<"Lineman ";}
        if(sp<=q.ss && we>=q.mw && st>=q.ms){val=1;cout<<"Quarterback ";}
        if(val==1)cout<<endl;
        else cout<<"No positions"<<endl;                     
    }
    
    system("pause");
    return 0;
}
