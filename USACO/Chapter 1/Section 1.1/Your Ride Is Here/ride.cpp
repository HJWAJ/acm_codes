/*
ID: hjw00002
PROG: ride
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char s1[10],s2[10];
    while(fin>>s1>>s2)
    {
        int p1,p2,i;
        p1=p2=1;
        int len1=strlen(s1),len2=strlen(s2);
        for(i=0;i<len1;i++)p1*=(s1[i]-'A'+1);
        for(i=0;i<len2;i++)p2*=(s2[i]-'A'+1);
        if(p1%47==p2%47)fout<<"GO"<<endl;
        else fout<<"STAY"<<endl;                    
    }
        
    return 0;
}
