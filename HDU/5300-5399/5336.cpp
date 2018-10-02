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
#include <queue>
#include <vector>
using namespace std;

const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Position
{
    int x, y;
    bool operator < (const Position b) const
    {
        if (x == b.x) return y < b.y;
        return x < b.x;
    }
};
struct WaterDrop
{
    Position position;
    int size;
    int crackTime;
    bool exists;
};
struct SmallDrop
{
    int id;
    Position position;
    int dx;
    int dy;
};

map<int, SmallDrop> smallDrops;
WaterDrop waterDrops[10005];
map<Position, WaterDrop*> waterDropMap;
char g[105][105];
vector<int> smallDropsToErase;

void printSmallDrops()
{
    for (map<int, SmallDrop>::iterator it = smallDrops.begin(); it != smallDrops.end(); it++)
    {
        printf("SmallDrop #%d: at (%d, %d), dir is (%d %d)\n",
               it->first, it->second.position.x, it->second.position.y,
               it->second.dx, it->second.dy);
    }
}

void printWaterDrops(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("WaterDrop #%d: at (%d, %d), size is %d, crackTime is %d, %s\n",
               i, waterDrops[i].position.x, waterDrops[i].position.y, waterDrops[i].size, waterDrops[i].crackTime,
               waterDrops[i].exists ? "exists" : "not exist");
    }
}

int main()
{
    int r, c, n, time, curTime, startx, starty, id;
    while (scanf("%d%d%d%d", &r, &c, &n, &time) != EOF)
    {
        memset(g, 0, sizeof(g));
        curTime = 0;
        waterDropMap.clear();
        smallDrops.clear();
        id = 0;

        for (int i = 0; i < n; i++)
        {
            Position p;
            scanf("%d%d", &p.x, &p.y);
            waterDrops[i].position = p;
            scanf("%d", &waterDrops[i].size);
            waterDrops[i].exists = 1;
            waterDropMap[p] = &waterDrops[i];
            g[p.x][p.y] = '#';
        }

        scanf("%d%d", &startx, &starty);
        for (int i = 0; i < 4; i++)
        {
            SmallDrop smallDrop;
            smallDrop.id = id++;
            smallDrop.position.x = startx;
            smallDrop.position.y = starty;
            smallDrop.dx = dir[i][0];
            smallDrop.dy = dir[i][1];
            smallDrops[smallDrop.id] = smallDrop;
        }

        while (curTime < time)
        {
            curTime++;

            //printSmallDrops();
            //printWaterDrops(n);
            //getchar();

            smallDropsToErase.clear();

            for (map<int, SmallDrop>::iterator it = smallDrops.begin(); it != smallDrops.end(); it++)
            {
                it->second.position.x += it->second.dx;
                it->second.position.y += it->second.dy;
                if (it->second.position.x <= 0 || it->second.position.x > r
                    || it->second.position.y <= 0 || it->second.position.y > c)
                {
                    smallDropsToErase.push_back(it->first);
                }
                else if (g[it->second.position.x][it->second.position.y] == '#')
                {
                    waterDropMap[it->second.position]->size++;
                    smallDropsToErase.push_back(it->first);
                }
            }

            for (int i = 0; i < smallDropsToErase.size(); i++)
            {
                smallDrops.erase(smallDropsToErase[i]);
            }

            for (int i = 0; i < n; i++)
                if (waterDrops[i].size > 4 && waterDrops[i].exists)
                {
                    g[waterDrops[i].position.x][waterDrops[i].position.y] = '\0';
                    waterDrops[i].crackTime = curTime;
                    waterDrops[i].exists = 0;

                    for (int j = 0; j < 4; j++)
                    {
                        SmallDrop smallDrop;
                        smallDrop.id = id++;
                        smallDrop.position.x = waterDrops[i].position.x;
                        smallDrop.position.y = waterDrops[i].position.y;
                        smallDrop.dx = dir[j][0];
                        smallDrop.dy = dir[j][1];
                        smallDrops[smallDrop.id] = smallDrop;
                    }
                }
        }

        for (int i = 0; i < n; i++)
        {
            if (waterDrops[i].exists) printf("1 %d\n", waterDrops[i].size);
            else printf("0 %d\n", waterDrops[i].crackTime);
        }
    }
    return 0;
}
