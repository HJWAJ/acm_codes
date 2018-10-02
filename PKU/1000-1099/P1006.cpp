#include<iostream>
using namespace std;

int main()
{
    int a[32768][4];
    int i=0;
    
    for(int j=0;j<4;j++)
        cin>>a[i][j];
    
    while(a[i][0]!=-1||a[i][1]!=-1||a[i][2]!=-1||a[i][3]!=-1)
    {
        i++;
        for(int j=0;j<4;j++)
        cin>>a[i][j];
    }
    
    for(int n=0;n<i;n++)
    {
        int d,dd;
        for(d=0;d<21253;d++)
            {if(((d+a[n][0])%23==0)&&((d+a[n][1])%28==0)&&((d+a[n][2])%33==0)) break;
            if(d>21252)d-=21252;}
        dd=21252-(d+a[n][3]);
        if(dd<0)dd+=21252;
        cout<<"Case "<<n+1<<": the next triple peak occurs in "<<dd<<" days."<<endl;        
    }
    
    system("pause");
    return 0;
}
