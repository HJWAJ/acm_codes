#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
vector < list<int> > v;
stack<int> s;
bool bo[105];
int main()
{
    int n,i,j,tmp;
    while(scanf("%d",&n)!=EOF)
    {
        memset(bo,0,sizeof(bo));
        v.clear();
        v.resize(n);
        for(i=0;i<n;i++)
            while(scanf("%d",&tmp) && tmp)
                v[i].push_back(tmp-1);
        while(s.size()<n)
        {
            for(i=0;i<n;i++)
                if(!v[i].size() && !bo[i])
                {
                    for(j=0;j<n;j++)
                        v[j].remove(i);
                    s.push(i+1);
                    bo[i]=1;
                    break;
                }
        }
        printf("%d",s.top());
        s.pop();
        while(!s.empty())
        {
            printf(" %d",s.top());
            s.pop();
        }
        puts("");
    }
    return 0;
}
