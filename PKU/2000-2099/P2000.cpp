#include<iostream>
using namespace std;

int main()
{
    int day[30],gold[30];
    int i=0;
    
    cin>>day[i];
    while(day[i]!=0)
    {
        i++;
        cin>>day[i];                
    }
    
    for(int n=0;n<i;n++)
    {
        int m=0;
        while(m*(m+1)/2<=day[n])m++;
        gold[n]=(day[n]-m*(m-1)/2)*m+(m-1)*m*(2*m-1)/6;
        cout<<day[n]<<' '<<gold[n]<<endl;    
    }
    
    system("pause");
    return 0;    
}
