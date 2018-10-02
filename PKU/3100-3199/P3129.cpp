#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,m,i,j,s,t;
    bool f;
    double x[500],y[500],z[500],a[50],b[50],c[50],d[50];
    int p[500];
    
    s=0;
    while(cin>>n && n!=0) 
    {
        i=1;
        while(i<=n) 
        {  
            cin>>x[i]>>y[i]>>z[i];
            f=0;
            for(j=1;j<i;j++)
                if(x[i]==x[j] && y[i]==y[j] && z[i]==z[j])
                    f=1;
            if(f==1){n--;continue;}
            i++;
        }
        cin>>m;
        for(i=1;i<=m;i++) {cin>>a[i]>>b[i]>>c[i]>>d[i];}
        s++;
        t=0;
        for(i=1;i<=n;i++)
        {	
            j=1;f=0;
		    while (f==0 && j<=m)
	        { 
                if(((x[i]*a[j]+y[i]*b[j]+z[i]*c[j])/(sqrt(x[i]*x[i]+y[i]*y[i]+z[i]*z[i])*sqrt(a[j]*a[j]+b[j]*b[j]+c[j]*c[j])))>cos(d[j])) f=1;
                j++;
            }
            if(f==1)t++;
        }
        p[s]=t;
    }
    for(i=1;i<=s;i++) cout<<p[i]<<endl;
    
    system("pause");
    return 0;
    
}
