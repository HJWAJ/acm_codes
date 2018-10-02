#include<iostream>
using namespace std;

int cube(int n)
{ 
    return n*n*n; 
}

int main()
{ 
    int a,m[120];int i,j,k,l;
    for(int w=1;w<=110;w++)
	    m[w]=cube(w);
    cin>>a;
    for(i=2;i<=a;i++)
    { 
        for(j=2;j<=a;j++)
        for(k=j+1;k<=a;k++)
		    for(l=k+1;l<=a;l++)
			    if((m[i])==(m[j]+m[k]+m[l])) 
			  	     cout<<"Cube = "<<i<<','<<" Triple = ("<<j<<','<<k<<','<<l<<')'<<endl;
    }
    system("pause");
    return 0;
}
