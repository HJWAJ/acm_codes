#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[1000];
    while(cin.getline(s,1000) && strcmp(s,"#")!=0)
    {
        int len=strlen(s);
        int i,j;
        for(i=0;i<len;i++)
        {
            if(s[i]==' ')cout<<"%20";
            else if(s[i]=='!')cout<<"%21";
            else if(s[i]=='$')cout<<"%24";
            else if(s[i]=='%')cout<<"%25";
            else if(s[i]=='(')cout<<"%28";
            else if(s[i]==')')cout<<"%29";
            else if(s[i]=='*')cout<<"%2a";
            else cout<<s[i];
        }   
        cout<<endl;  
        memset(s,0,sizeof(s));                     
    }    
    
    system("pause");
    return 0;
}
