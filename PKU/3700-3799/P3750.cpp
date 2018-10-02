#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,w,s,k;
    char a[100][20],p;
    
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>w>>p>>s;
    
    k=n;
    w-=1;
    for(int i=0;i<k;i++)
    {
        w=(w+s-1)%n;
        cout<<a[w]<<endl;
        
        for(int j=w+1;j<n;j++)
        strcpy(a[j-1],a[j]); 
        n--;
    }
    
    system("pause");
    return 0;
}
