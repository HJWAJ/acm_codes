#include<iostream>
using namespace std;

int main()
{
	int d;
	while(cin>>d && d!=0)
	{
	    int p[100000];
	    int i,j;
	    for(i=0;i<d;i++)
            cin>>p[i];
        i=0;
        j=d-1;
        int s1=0,s2=0;
        while(i<=j)
	    {
            if(s1>s2){s2+=p[j];j--;}
	        else {s1+=p[i];i++;}
	    }
	    if(s1!=s2)cout<<"No equal partitioning."<<endl;
        else cout<<"Sam stops at position "<<j+1<<" and Ella stops at position "<<i+1<<'.'<<endl;
	}
	
    system("pause");
    return 0;
}
