#include<iostream>
using namespace std;

int main()
{
    int s,b[256];
    char a[256];
    cin.getline(a,256);
    while(a[0]!='#')
    {
        s=0;
        int i=0; 
        while(a[i]!='\0')
        {
            if(a[i]==' ')b[i]=0;
            else b[i]=a[i]-'A'+1;
            s=s+(i+1)*b[i];                 
            i++;
        }           
        cout<<s<<endl;            
                    
        cin.getline(a,256);
    }    
    
    system("pause");
    return 0;
}
