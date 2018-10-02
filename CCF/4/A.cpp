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
using namespace std;
map<int, int> mymap;
vector<int> ans;
int main()
{
    int n, a;
    while (scanf("%d", &n) != EOF)
    {
        mymap.clear();
        ans.clear();
        while (n--)
        {
            scanf("%d", &a);
            mymap[a]++;
            ans.push_back(mymap[a]);
        }
        for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
        //printf("%d\n", ans[ans.size() - 1]);
        puts("");
    }
    return 0;
}
