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
int main()
{
    __int64 n, m, a, x, y;
    scanf("%I64d%I64d%I64d", &n, &m, &a);
    if (n % a == 0) x = n / a;
    else x = n / a + 1;
    if (m % a == 0) y = m / a;
    else y = m / a + 1;
    printf("%I64d\n", x * y);
    return 0;
}
