#include<iostream>
#define maxn 3010
using namespace std;

int a[maxn],b[maxn],next[maxn],n;
bool used[maxn];

int main()
{
    int i,j,k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        k+=a[i];
        used[i]=0;
    }
    for(i=0;i<n-k;i++)b[i]=0;
    for(i=n-k;i<n;i++)b[i]=1;
    for(i=0;i<n;i++)
    {
        j=0;
        while(b[i]!=a[j] || used[j]==1)j++;
        next[i]=j;
        used[j]=1;
    }
    j=0;
    for(i=0;i<n;i++)
    {
        j=next[j];
        cout<<a[j]<<' ';
    }
    cout<<endl;

    system("pause");
    return 0;
}
