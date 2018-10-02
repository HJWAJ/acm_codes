#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
    int p;
    bool bo;
};
int main()
{
    queue<node> q;
    node tmp;
    int t,n,m,a[105],i,num,pri;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        num=0;
        while(!q.empty())q.pop();
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            tmp.p=a[i];
            if(i==m)
            {
                tmp.bo=1;
                pri=a[i];
            }
            else tmp.bo=0;
            q.push(tmp);
        }
        sort(a,a+n);
        n--;
        while(a[n]>pri)
        {
            tmp=q.front();
            q.pop();
            if(a[n]>tmp.p)q.push(tmp);
            else
            {
                n--;
                num++;
            }
        }
        while(1)
        {
            tmp=q.front();
            q.pop();
            if(tmp.p<pri)q.push(tmp);
            else num++;
            if(tmp.bo)break;
        }
        printf("%d\n",num);
    }
    return 0;
}
