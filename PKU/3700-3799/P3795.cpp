#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<ctime>
using namespace std;
long long a[]={1, 9, 89, 89, 589, 3089, 3089, 3089, 315589, 315589, 8128089, 164378089, 945628089, 1922190589LL, 11687815589LL, 109344065589LL, 231414378089LL, 1452117503089LL, 4503875315589LL, 65539031565589LL};
int main()
{
    int n,r,k=0;
    scanf("%d",&n);
    while(n--)
    {
        k++;
        scanf("%d",&r);
        printf("%d %d %I64d\n",k,r,a[r-1]);
    }
    return 0;
}
