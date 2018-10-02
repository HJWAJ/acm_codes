#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int i,a[1005];
    for(i=0;i<n;i++)scanf("%d",a+i);
    int l,r;
    for(i=0;i<n;i++)
        if(a[i]!=i+1){l=i;break;}
    if(i==n){printf("0 0\n");exit(0);}
    for(i=n-1;i>=0;i--)if(a[i]!=i+1){r=i+1;break;}
    for(i=0;i<(r-l)/2;i++)swap(a[l+i],a[r-1-i]);
    for(i=l;i<r;i++)
        if(a[i]!=i+1){printf("0 0\n");exit(0);}
    if(i==r)printf("%d %d\n",l+1,r);
    
    //for(i=0;i<n;i++)cout<<a[i]<<' ';
    
    //system("pause");
    return 0;
}
