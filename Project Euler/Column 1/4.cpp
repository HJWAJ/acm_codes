#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int i,j,k,num,p,max=0;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            for(k=0;k<10;k++)
            {
                num=i*100001+j*10010+k*1100;
                for(p=100;p<1000;p++)
                    if(num%p==0 && num/p>=100 && num/p<1000 && num>max)max=num;
            }
    printf("%d\n",max);
    return 0;
}

