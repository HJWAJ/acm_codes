#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
using namespace std;
char s[5005][5005];
int n;
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(i!=j && s[i][j]=='1')
                for(k=0;k<n;k++)
                    if(k!=i && k!=j && s[j][k]=='1' && s[k][i]=='1')
                    {
                        printf("%d %d %d",i+1,j+1,k+1);
                        return 0;
                    }
    puts("-1");
    return 0;
}
