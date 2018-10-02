#include<iostream>
using namespace std;

int main()
{
    int n,a[1000];
    memset(a,0,sizeof(a));
    cin>>n;
    int i=0,j=2;
    while(n>=j){n-=j;a[i]=j;j++;i++;}
    for(j=0;j<i;j++)a[j]+=n/i;
    n%=i;
    for(j=i-1;n!=0;j--){a[j]++;n--;}
    i=0;
    while(a[i]!=0){cout<<a[i]<<' ';i++;}
    cout<<endl;
    
    system("pause");
    return 0;
}
