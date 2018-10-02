#include <iostream>
using namespace std;
int main()
{
    char s[30];
    int i,j;
    while(cin>>s)
    {
        int a[30]={0};
        j=0;
        for(i=0;i<strlen(s);i++)
        {
        switch(s[i])
        {case 'B':case 'F':case 'P':case 'V':
            a[j]=1;j++;break;
        case 'C':case 'G':case 'J':case 'K':case 'Q':case 'S':case 'X':case'Z':
            a[j]=2;j++;break;
        case 'D':case 'T':
            a[j]=3;j++;break;
        case 'L':
            a[j]=4;j++;break;
        case 'M':case 'N':
            a[j]=5;j++;break;
        case 'R':
            a[j]=6;j++;break;
        default:a[j]=7;j++;break;
        }
        if((a[j-1]!=a[j-2]) && (a[j-1]!=7)&& (a[j-1]!=0))cout<<a[j-1];
       
        }
        cout<<endl;
        }
        system("pause");
       return 0;
}

