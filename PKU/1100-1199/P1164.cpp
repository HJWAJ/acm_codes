#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n,m,map[60][60];
bool val[60][60];
int Max;

void floodfill(int x,int y,int &c)
{
    val[x][y]=false,c++;
    if(val[x][y-1] && map[x][y]%2==0)floodfill(x,y-1,c);
    if(val[x-1][y] && map[x][y]%4/2==0)floodfill(x-1,y,c);
    if(val[x][y+1] && map[x][y]%8/4==0)floodfill(x,y+1,c);
    if(val[x+1][y] && map[x][y]/8==0)floodfill(x+1,y,c);
}

int main()
{
    int i,j,count,total=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>map[i][j];
            val[i][j]=true;
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(val[i][j])
            {
                total++,count=0;
                floodfill(i,j,count);
                Max=max(Max,count);
            }
    cout<<total<<endl<<Max<<endl;
    
    system("pause");
    return 0;
}
