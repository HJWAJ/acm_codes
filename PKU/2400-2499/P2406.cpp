#include<iostream>
#include<cmath>
#include<string>
using namespace std;

char s[1000005];
int a[10000];

int main()
{
    while(scanf("%s",s) && s[0]!='.')
    {
        string str;
        str=s;
        string c="";
        for(int i=0;i<str.size();i++)
        {
            string a="";
            c+=str[i];
            if(str.size()%c.size()!=0)continue;
            int temp=str.size()/c.size();
            for(int j=1;j<=temp;j++)a+=c;
            if(a==str)
            {
                printf("%d\n",temp);
                break;
            }
        }       
    }    
    
    system("pause");
    return 0;
}
