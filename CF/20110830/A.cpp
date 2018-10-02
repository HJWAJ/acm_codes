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
    char s[20];
    int len,cnt=0,i;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
        if(s[i]=='4' || s[i]=='7')cnt++;
    if(cnt==4 || cnt==7)puts("YES");
    else puts("NO");
	return 0;
}
