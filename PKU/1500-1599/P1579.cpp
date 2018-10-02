#include<iostream>
#include<cstring>
using namespace std;

int result[21][21][21];

int w(int a,int b,int c)
{
    if(a<=0 || b<=0 || c<=0)return 1;
    if(a>20 || b>20 || c>20)return result[20][20][20]=w(20,20,20);
    if(result[a][b][c]!=0)return result[a][b][c];                   //¼ÇÒä 
    if(a<b && b<c)return result[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return result[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);   
}

int main()
{
    int a,b,c;
    while(cin>>a>>b>>c&&(a!=-1||b!=-1||c!=-1))
    {
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
    }    
    
    system("pause");
    return 0;
}
