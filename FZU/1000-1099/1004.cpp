#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
using namespace std;
int a[1005][1005];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<i+1;j++)
                scanf("%d", &a[i][j]);
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<=i;j++)
            {
                if(a[i+1][j]>a[i+1][j+1])a[i][j]+=a[i+1][j];
                else a[i][j]+=a[i+1][j+1];
            }
        printf("%d\n", a[0][0]);
    }
    return 0;
}
