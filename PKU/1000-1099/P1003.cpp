#include<iostream>
using namespace std;

int main()
{
    float a[10000];
    int i=0;
    cin>>a[i];
    while(a[i]!=0.00)
    {
        i++;
        cin>>a[i];                 
    }
    
    
    for(int k=0;k<i;k++)
    {
      float s=0;
      float n=2;
      while(s<=a[k])
    {
        s+=1/n;
        n++;              
    }
    cout<<n-2<<" card(s)"<<endl;
    }
    
    system("pause");
    return 0;
}
