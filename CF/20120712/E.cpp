#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
char s1[200005],s2[200005];
double n1[26],n2[26];
int main()
{
    int n,i;
    double sum=0;
    scanf("%d%s%s",&n,s1,s2);
    for(i=0;i<n;i++)
    {
        sum+=(n-i)*n2[s1[i]-'A'];
        sum+=(n-i)*n1[s2[i]-'A'];
        if(s1[i]==s2[i])sum+=1.0*(i+1)*(n-i);
        n1[s1[i]-'A']+=i+1;
        n2[s2[i]-'A']+=i+1;
    }
    printf("%.16lf\n",sum*6/n/(n+1)/(2*n+1));
    return 0;
}
