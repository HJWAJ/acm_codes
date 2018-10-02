#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
inline int x(int a, int b, int c)
{
    return a ^ b ^ c;
}
int main()
{
    int cnt = 0;
    for (int i = 1; i <= (1 << 30); ++i)
        if (x(i, i << 1, i + (i << 1)) == 0)
            cnt++;
    cout << cnt << endl;
	return 0;
}
