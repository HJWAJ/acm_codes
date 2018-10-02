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
map<string,string> mymap;
int main()
{
	int i;
	char tmp[25],s[15];
	string str1,str2;
	mymap.clear();
	while(gets(tmp) && strcmp(tmp,""))
	{
	    i=0;
	    while(tmp[i]!=' ')i++;
	    tmp[i]='\0';
	    str1=tmp;
	    str2=tmp+i+1;
	    mymap[str2]=str1;
	}
	memset(tmp,0,sizeof(tmp));
	while(scanf("%s",tmp)!=EOF)
	{
	    str1=tmp;
	    if(mymap.find(str1)!=mymap.end())
	    {
	        strcpy(s,mymap[str1].c_str());
	        puts(s);
	    }
	    else puts("eh");
	}
	return 0;
}
