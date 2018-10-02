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
#include <memory.h>
#include<assert.h>
using namespace std;

int main()
{
	int n,ans1,ans2;	
	int Icase=1;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)break;
		if(n==2||n>147)printf("-1\n");
		else
		{
			ans1 = 0;
			if (n == 0)ans1 = 147;
			else if (n <= 120)
			{
				int k = (n - 1) / 8 + 1;
				ans1 = (15 - k)*8 + 27;
			}
			else if (n <= 122)ans1 = 25;
			else if (n <= 125)ans1 = 22;
			else if (n <= 129)ans1 = 18;
			else if (n <= 134)ans1 = 13;
			else if (n <= 140)ans1 = 7;			
			ans2 =  0;
			if (n == 0)ans2 =  72;
			else if (n <= 45)
			{
				int k = (n - 1) / 3 + 1;
				ans2 =  (15 - k)*3 + 27;
			}
			else if(n==46)ans2 =  27;
			else if (n <= 49)ans2 =  25;
			else if (n <= 53)ans2 =  22;
			else if (n <= 58)ans2 =  18;
			else if (n <= 64)ans2 =  13;
			else 	if (n <= 71)ans2 =  7;
			if(ans1 == ans2)printf("%d\n",ans1);
			else printf("%d %d\n",ans1,ans2);
			if(ans1>n)printf("Yes\n");
			else printf("No\n");
		}

	}
	return 0;
}