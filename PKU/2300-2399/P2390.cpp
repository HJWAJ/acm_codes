#include<iostream>
using namespace std;

int main()
{
    int r,m,y,i;
    double rr,mm;
    cin>>r>>m>>y;
    mm=double(m);
    rr=double(r);
    for(i=0;i<y;i++)mm=mm*(1+rr/100.0);
    cout<<int(mm)<<endl;
    
    system("pause");
    return 0;
}
