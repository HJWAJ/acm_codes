#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,s,l[20000];
    int i,j,count=0;
    cin>>n>>s;
    for(i=0;i<n;i++)cin>>l[i];
    sort(l,l+n);
    j=n-1;
    for(i=0;i<n;i++)
    {
        if(l[i]>=s) break;
        while(l[i]+l[j]>s)j--;
        if(j<=i)break;
        count=count+j-i;              
    }
            
    cout<<count<<endl;    
    
    system("pause");
    return 0;
}
