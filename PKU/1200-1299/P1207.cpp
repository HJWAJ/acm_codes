#include<iostream>
using namespace std;

int main()
{
    int i,j,temp,count,countm=0;
    while(cin>>i>>j)
    {
        countm=0;
        if(i<j)
        {
        for(int k=i;k<=j;k++)
        {
            temp=k;
            count=0;
            while(temp!=1)
            {
                if(temp%2==1)temp=temp*3+1;
                else temp/=2;
                count++;
            }        
            if(count>=countm)
            {
                countm=count;
            }
        }
        }
        else
        {
        for(int k=j;k<=i;k++)
        {
            temp=k;
            count=0;
            while(temp!=1)
            {
                if(temp%2==1)temp=temp*3+1;
                else temp/=2;
                count++;
            }        
            if(count>=countm)
            {
                countm=count;
            }
        }
        }
        cout<<i<<' '<<j<<' '<<countm+1<<endl;               
    }
    
    system("pause");
    return 0;
}
