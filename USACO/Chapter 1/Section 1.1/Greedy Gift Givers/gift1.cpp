/*
ID: hjw00002
PROG: gift1
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
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    char s[10][15],str[15];
    int val[10];
    memset(val,0,40);
    int n,i,j,k;
    fin>>n;
    for(i=0;i<n;i++)fin>>s[i];
    for(k=0;k<n;k++)
    {
        fin>>str;
        int num,sum;
        fin>>sum>>num;
        if(num==0)continue;
        for(i=0;i<n;i++)
            if(strcmp(str,s[i])==0)break;
        val[i]-=sum;
        val[i]+=(sum-sum/num*num);
        sum/=num;
        for(i=0;i<num;i++)
        {
            memset(str,0,sizeof(str));
            fin>>str;
            for(j=0;j<n;j++)if(strcmp(str,s[j])==0)break;
            val[j]+=sum;                  
        }               
    }
    for(i=0;i<n;i++)fout<<s[i]<<' '<<val[i]<<endl;
    
    //system("pause");
    return 0;
}
