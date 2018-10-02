/*
ID: hjw00002
PROG: dualpal
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

int rev(int n,int b)
{
    int res=0;
    while(n)
    {
        res*=b;
        res+=(n%b);
        n/=b;        
    }    
    return res;
}

int main()
{
    freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
    int n,l,i;
    scanf("%d%d",&n,&l);
    while(n)
    {
        l++;
        int cnt=0;
        for(i=2;i<=10;i++)
        {
            if(l==rev(l,i))cnt++;                  
        }
        if(cnt>=2){printf("%d\n",l);n--;}
    }
    
    //system("pause");
    return 0;
}
