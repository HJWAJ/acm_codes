#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    char s[10000];
    string ss;
    int i,j,p=1;
    while(cin.getline(s,10000))
    {
        ss=s;
        while(ss.find('"')!=4294967295)
	    {	  
            if(p%2==1)ss.replace(ss.find('"'),1,"``");
            else ss.replace(ss.find('"'),1,"''");
       	    p++;
        } 
	    cout<<ss<<endl;                          
    }    
    
    //system("pause");
    return 0;
}
