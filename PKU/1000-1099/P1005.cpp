#include<iostream>
using namespace std;

int main()
{
    int n,i,j=0;
    float a[10000],b[10000];
    float s;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(i=0;i<n;i++)
    {
    while((s/3.141592653589)<(a[i]*a[i]+b[i]*b[i]))
    {
        s+=100;j++;                                       
    }
    cout<<"Property "<<i+1<<": This property will begin eroding in year "<<j<<"."<<endl;
    }
    cout<<"END OF OUTPUT.";
    system("pause");
    return 0;    
}
