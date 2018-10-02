#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    int n,a[1005],i,j;
    while(scanf("%d",&n) && n)
    {
        while(scanf("%d",a) && a[0])
        {
            for(i=1;i<n;i++)scanf("%d",a+i);
            j=1;
            s.push(-1);
            for(i=0;i<n;i++)
            {
                if(s.top()==a[i])
                {
                    s.pop();
                    continue;
                }
                while(s.top()!=a[i])
                {
                    s.push(j);
                    j++;
                    if(s.top()==a[i])break;
                    if(j>n)
                    {
                        printf("No\n");
                        goto label;
                    }
                }
                if(s.top()==a[i])
                {
                    s.pop();
                    continue;
                }
            }
            printf("Yes\n");
            label:;
        }
        printf("\n");
    }
    return 0;
}
