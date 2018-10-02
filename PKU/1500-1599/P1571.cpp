#include<iostream>
using namespace std;

int main()
{
    int mon,t,m[1000];
    double ini,all,a[1000];
    while(cin>>mon>>ini>>all>>t && mon>=0)
    {
        int i,j;
        for(i=0;i<t;i++)cin>>m[i]>>a[i];
        double carvalue=ini+all;
        double per=all/double(mon);
        i=1;
        j=1;
        if(m[0]==0)carvalue*=(1-a[0]);
        while(carvalue<=all)
        {
            if(m[j]==i)j++;
            carvalue*=(1-a[j-1]);   
            all-=per;
            i++;                    
        }      
        i--;                 
        if(i==1)cout<<i<<" month"<<endl;
        else cout<<i<<" months"<<endl;     
    }    
    
    system("pause");
    return 0;
}
