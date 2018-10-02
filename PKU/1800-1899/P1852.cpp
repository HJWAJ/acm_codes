#include<iostream>
using namespace std;

int main()
{
    int t,n,m,a[100000],a1[100000],a2[100000],max1,max2,i;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        max1=max2=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>m-a[i])
            {
                a1[i]=a[i];
                a2[i]=m-a[i];
            }
            else
            {
                a1[i]=m-a[i];
                a2[i]=a[i];    
            }
            if(max1<a2[i])max1=a2[i];
            if(max2<a1[i])max2=a1[i];          
        }
        cout<<max1<<' '<<max2<<endl;
    }
    
    system("pause");
    return 0;
}
