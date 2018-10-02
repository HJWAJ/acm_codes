#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n,d,a[100],i,j;
	while(cin>>n>>d && n!=0 || d!=0)
	{
        memset(a,0,sizeof(a));
        if(d==0){cout<<1<<endl;continue;}
        a[0]=n%10;
        a[1]=n/10;
        for(i=1;i<d;i++)
        {
            for(j=0;j<99;j++)
            {
                a[j]*=n;                  
            }           
            for(j=0;j<99;j++)
            {
                a[j+1]=a[j+1]+a[j]/10;
                a[j]%=10;                  
            }     
        }
        i=99;
        while(a[i]==0)i--;
        for(j=i;j>=0;j--)cout<<a[j];
        cout<<endl;
    }
	
	system("pause");
	return 0;
}
