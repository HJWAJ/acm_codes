#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char a[1000],b[1000];
    int n,i,cnt1,cnt2;
    while(cin>>a>>b && strcmp(a,"E")!=0 || strcmp(b,"E")!=0)
    {
        n=strlen(a);
        cnt1=cnt2=0;
        for(i=0;i<n;i++)    
        {                
            if((a[i]=='R' && b[i]=='S') || (a[i]=='P' && b[i]=='R') || (a[i]=='S' && b[i]=='P'))cnt1++;
            if((b[i]=='R' && a[i]=='S') || (b[i]=='P' && a[i]=='R') || (b[i]=='S' && a[i]=='P'))cnt2++;                    
        } 
        cout<<"P1: "<<cnt1<<endl<<"P2: "<<cnt2<<endl;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));           
    }    
    
    system("pause");
    return 0;
}
