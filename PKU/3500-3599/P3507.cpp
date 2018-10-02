#include<iostream>
using namespace std;

int main()
{
    double a[6];
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5] && (a[0]!=0 || a[1]!=0 || a[2]!=0 || a[3]!=0 || a[4]!=0 || a[5]!=0))
    {
        double min=a[0];
        double max=a[0];
        double sum=0;
        int i;
        for(i=0;i<6;i++)
        {
            if(min>a[i])min=a[i];
            if(max<a[i])max=a[i];
            sum+=a[i];
        }
        double avr=(sum-max-min)/4.0;
        cout<<avr<<endl;                            
    }   
    
    system("pause");
    return 0;
}
