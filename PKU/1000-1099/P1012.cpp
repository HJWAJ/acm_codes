#include<iostream>
using namespace std;


int main()
{
	int k=0,a[14]={0};
	while( (cin>>k)&&(k!=0) )
	{
		if(a[k]!=0)
		{
			cout<<a[k]<<endl;
			continue;
		}	

		for(int m=k+1;;m++)
		{
			int n=2*k,i=0,flag=0;
			while(1)
			{
				i=(i+m-1)%n;
				if(i>=0&&i<k) break;
				else flag++;
				n--;
            }
			
			
            if(flag==k) 
			{
				a[flag] = m;
				cout<<m<<endl; 
				break;
			}
		}	
	}
	
	system("pause");
	return 0;
}
