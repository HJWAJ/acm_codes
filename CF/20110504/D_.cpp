#include<stdio.h>
#include<math.h>
#include<vector>
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

struct NODE
{
    int val;
    int id;
}x[44];

int cmp(NODE a,NODE b)
{
    return a.val > b.val;
}

int res[1010];

int main()
{
    int n,m;
    cin>>n>>m;
    int sum = 0;
    for(int i = 0 ; i < m ; i ++)
    {
        cin>>x[i].val;
        x[i].val = min(x[i].val,n/2);
        x[i].id = i + 1;
        sum += x[i].val;
    }
    sort(x,x+m,cmp);
    vector<int>ans;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < x[i].val; j++) 
            ans.push_back(x[i].id);
    }
    if(sum < n) { printf("-1\n"); return 0; }
    int index = 0;
    for(int i = 0; i < n; i += 2) {
        res[i] = ans[index++];
    }
    while(ans[index] == x[0].id) index++;
    for(int i = 1; i < n; i += 2) 
        res[i] = ans[index++];
    for(int i = 0; i < n; i++)
        printf("%d%c", res[i], i == n-1 ? '\n' : ' ');

}
