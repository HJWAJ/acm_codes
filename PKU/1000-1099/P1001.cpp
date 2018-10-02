#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	unsigned int a[100];
    unsigned int b[100];
    unsigned int result[100];
    char arr[100];
    int n,i,j,k,len,len_a,len_b,jinwei,p,xiaoshu;
	bool flag;

	while(cin>>arr>>n)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(result,0,sizeof(result));
		len=strlen(arr);
		flag=false;
		for(i=len-1,j=0;i>=0;i--)
		{
			if(arr[i]=='.')
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{
			i=len-1;
			while(arr[i]=='0')i--;
			if(arr[i]=='.')
			{
				i--;
				flag=false;
			}
		}

		for(;i>=0;i--)
		{
			if(arr[i]!='.')
			{
				a[j]=arr[i]-'0';
				b[j]=arr[i]-'0';
				j++;
			}
			else xiaoshu=j;
		}
		len_a=len_b=j;

		i=0;
		while(flag)
		{
			if((arr[i]>'0' && arr[i]<='9'))
			{
				i++;
				break;
			}
			else if(arr[i]=='.')i++;
			else
			{
				len_a--;
				len_b--;
				i++;
			}
		}
		xiaoshu=xiaoshu*n;

		while(--n)
		{
			memset(result,0,sizeof(result));
			for(i=0;i<len_a;i++)
			{
				for(j=0;j<len_b;j++)
				{
					result[i+j]=result[i+j]+a[i]*b[j];
				}
			}
			len_a=len_a+len_b;
			jinwei=0;
			for(i=0; i<len_a; i++)
			{
				result[i]+=jinwei;
				jinwei=result[i]/10;
				result[i]%=10;
			}
			if(result[len_a-1]==0)len_a--;
			memset(a,0,sizeof(a));

			for(i=0;i<len_a;i++)a[i]=result[i];
        }

		if(flag)
		{
			if(len_a>xiaoshu)
			{
				j=len_a-xiaoshu+1;
				for(i=0;i<=j&&a[i]==0;)i++;
				k=i;
				
				if(i==j)
					for(i=len_a-1;i>=k;i--)cout<<a[i];
				
				else
				{
					j=len_a-xiaoshu;
					i=len_a-1;
					while(j--)cout<<a[i--];
					cout<<".";
					for(;i>=k;i--)cout<<a[i];
				}
			}
			else if(len_a==xiaoshu)
			{
				
				j=0;
				while(a[j]==0)j++;
				cout<<".";
				for(i=len_a-1;i>=j;i--)cout<<a[i];
			}
			else
			{
				cout<<".";
				
				j=xiaoshu-len_a;
				for(i=0;i<j;i++)cout<<"0";
				
				j=0;
				while(a[j]==0)j++;
				for(i=len_a-1;i>=j;i--)cout<<a[i];
			}
			cout<<endl;
		}
	
		else
		{
			for(i=len_a-1;i>=0;i--)cout<<a[i];
			cout<<endl;
		}
	}
	system("pause");
	return 0;
}
