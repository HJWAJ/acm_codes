#include<iostream>
using namespace std;

int main()
{
    int d[16];
    int r[1000],g[1000],b[1000];
    for(int i=0;i<16;i++)
        cin>>r[i]>>g[i]>>b[i];
    int i=16;
    cin>>r[i]>>g[i]>>b[i];
    while(r[i]!=-1 || g[i]!=-1 ||b[i]!=-1)
    {
        for(int j=0;j<16;j++)
           d[j]=(r[i]-r[j])*(r[i]-r[j])+(g[i]-g[j])*(g[i]-g[j])+(b[i]-b[j])*(b[i]-b[j]);
        int min=999999,k;
        for(int j=0;j<16;j++)  if(d[j]<min){min=d[j];k=j;}
        cout<<"("<<r[i]<<","<<g[i]<<","<<b[i]<<") maps to ("<<r[k]<<","<<g[k]<<","<<b[k]<<")"<<endl;
        i++;
        cin>>r[i]>>g[i]>>b[i];             
                   
                   
    }
    
    
    
    system("pause");
    return 0;
}
