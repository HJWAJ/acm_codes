#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    int a[10000],nn,i=0,j;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(cin>>a[i] && a[i]!=0)i++;
    for(j=0;j<i;j++)
    {
        if(a[j]==1){cout<<setw(5)<<a[j]<<"  DEFICIENT"<<endl;continue;}
        int s=0,k;
        nn=int(sqrt(double(a[j])));
        for(k=2;k<=nn;k++)
        {
            if(a[j]%k==0){s+=k;s+=a[j]/k;}                  
        }      
        s++;       
        if(s>a[j])cout<<setw(5)<<a[j]<<"  ABUNDANT"<<endl;
        else if(s<a[j])cout<<setw(5)<<a[j]<<"  DEFICIENT"<<endl;
        else cout<<setw(5)<<a[j]<<"  PERFECT"<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
    
    system("pause");
    return 0;
}
