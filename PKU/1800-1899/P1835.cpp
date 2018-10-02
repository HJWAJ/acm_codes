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
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
int x,y,z;
int nleft[6][6]={{-1,5,1,-1,2,4},
                 {2,-1,3,5,-1,0},
                 {4,0,-1,1,3,-1},
                 {-1,2,4,-1,5,1},
                 {5,-1,0,2,-1,3},
                 {1,3,-1,4,0,-1}};
int nright[6]={3,4,5,0,1,2};
int face,head,pace,i;
void go(int f)
{
    switch(f)
    {
    case 0:
        for(i=0;i<pace;i++)x++;
        break;
    case 1:
        for(i=0;i<pace;i++)y++;
        break;
    case 2:
        for(i=0;i<pace;i++)z++;
        break;
    case 3:
        for(i=0;i<pace;i++)x--;
        break;
    case 4:
        for(i=0;i<pace;i++)y--;
        break;
    case 5:
        for(i=0;i<pace;i++)z--;
        break;
    }
    return;
}
int main()
{
    int t,temp,n;
    char dir[15];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        face=0;head=2;
        x=y=z=0;
        while(n--)
        {
            scanf("%s %d",dir,&pace);
            switch(dir[0])
            {
            case 'f':
                go(face);
                break;
            case 'b':
                face = nright[face];
                go(face);
                break;
            case 'u':
                temp = head;
                head = nright[face];
                face = temp;
                go(face);
                break;
            case 'd':
                temp = head;
                head = face;
                face = nright[temp];
                go(face);
                break;
            case 'l':
                face = nleft[head][face];
                go(face);
                break;
            case 'r':
                face = nright[nleft[head][face]];
                go(face);
                break;
            }
        }
        printf("%d %d %d %d\n",x,y,z,face);
    }
    return 0;
}
