#include<iostream>
using namespace std;

int fib(int n)
{
    if(n==0)return 0;
    if(n==1)return 1;
    int ra,rb,a,b,x,y;
	ra=rb=a=b=1;
	n-=2;
	while(n!=0) 
    {
		if (n%2!=0)
        {
			x=ra*a+rb*b;
			y=ra*b+rb*(a-b+10000);
			ra=x%10000;rb=y%10000;
		}
		n/=2;
		x=a*a+b*b;
		y=(2*a+10000)*b-b*b;
		a=x%10000;
        b=y%10000;
	}
	return ra;    
}

int main()
{
    int n;
    while(cin>>n && n!=-1)
    {
        cout<<fib(n)<<endl;             
    }
    
    system("pause");
    return 0;
}
