#include<iostream>
using namespace std;

int main()
{
    int n,m;
    int i,j;
    char s[100][100];
    int a[100],b[100];
    
    cin>>n>>m;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>s[i][j];
                  
    for(i=0;i<m;i++)
         for(j=0;j<n;j++)
             for(int k=1;k<n-j;k++)
                if(s[i][j]>s[i][j+k])
                a[i]++;

    for(i=0;i<m;i++)
       b[i]=a[i];
    
    int temp;
    for(i=0;i<m;i++)
        for(j=0;j<m-1-i;j++)
            if(a[j]>a[j+1])
            {temp=a[j];    a[j]=a[j+1];    a[j+1]=temp;}
            
           
    for(i=0;i<m;i++)
       {for(j=0;j<m;)
           {if(a[i]==b[j])
               {for(int k=0;k<n;k++)cout<<s[j][k];break;}
           else j++;}
           cout<<endl;}
       
    system("pause");
    return 0;    
}
