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
    int n,seven,rest,four,i;
    scanf("%d",&n);
    seven=n/7;
    rest=n%7;
    if(!(rest&3))
    {
        four=rest/4;
        for(i=0;i<four;i++)printf("4");
        for(i=0;i<seven;i++)printf("7");
        puts("");
    }
    else
    {
        seven--;
        rest+=7;
        if(rest>n)puts("-1");
        else
        {
            if(!(rest&3))
            {
                four=rest/4;
                for(i=0;i<four;i++)printf("4");
                for(i=0;i<seven;i++)printf("7");
                puts("");
            }
            else
            {
                seven--;
                rest+=7;
                if(rest>n)puts("-1");
                else
                {
                    if(!(rest&3))
                    {
                        four=rest/4;
                        for(i=0;i<four;i++)printf("4");
                        for(i=0;i<seven;i++)printf("7");
                        puts("");
                    }
                    else
                    {
                        seven--;
                        rest+=7;
                        if(rest>n)puts("-1");
                        else
                        {
                            if(!(rest&3))
                            {
                                four=rest/4;
                                for(i=0;i<four;i++)printf("4");
                                for(i=0;i<seven;i++)printf("7");
                                puts("");
                            }
                            else puts("-1");
                        }
                    }
                }
            }
        }
    }
	return 0;
}
