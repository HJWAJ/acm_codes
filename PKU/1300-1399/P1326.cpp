#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
using namespace std;
int main()
{
    char s[10005];
    int num,sum=0;
    while(scanf("%s",s) && s[0]!='#')
    {
        if(s[0]=='0')
        {
            printf("%d\n",sum);
            sum=0;
            continue;
        }
        else
        {
            scanf("%s%d%s",s,&num,s);
            if(s[0]=='F')sum+=2*num;
            else if(s[0]=='B')sum+=(num+(num+1)/2);
            else
            {
                if(num<=500)sum+=500;
                else sum+=num;
            }
        }
    }
    return 0;
}
