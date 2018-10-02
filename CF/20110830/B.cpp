#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
int main()
{
    char s[]="abcd";
    int n,num=0;
    scanf("%d",&n);
    while(n--)
    {
        printf("%c",s[num]);
        num=(num+1)%4;
    }
    puts("");
	return 0;
}
