#include<iostream>
using namespace std;

int main()
{
    int n,p,a[1000][10];
    int i,j,k;
    int temp;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>p;
        for(j=0;j<10;j++)
            cin>>a[i][j];
    }    
    for(i=0;i<n;i++)
    {for(k=0;k<9;k++)
    {
        for(j=0;j<(9-k);j++)
        {
            if(a[i][j]<a[i][j+1])
            {
                temp=a[i][j];
                a[i][j]=a[i][j+1];
                a[i][j+1]=temp;
            }
        }
    }}
    for(i=0;i<n;i++)
    cout<<i+1<<" "<<a[i][2]<<endl;
    
    system("pause");
    return 0;
}
