#include <iostream>
#include <cstring>
using namespace std;
const int dir[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
long long prime[1000000];
unsigned char bo[9000001];
unsigned char bo2[5][8000000];
int prime_table()
{
    long long i, j, flag=0;
    memset(bo, 0, sizeof(bo));
    bo[0] = bo[1] = 1;
    for (i = 2; i <= 3000; i++)
        if(!bo[i])
        {
            j = i * i;
            for (; j <= 9000000; j += i) bo[j] = 1;
        }
    for (i = 0; i <= 9000000; i++)
        if(!bo[i]) prime[flag++] = i;
    return flag;
}
pair<long long, long long> get_coord(long long num, long long n)
{
    pair<long long, long long> pii;
    pii.first = 0;
    pii.second = num;
    n -= 2;
    while (pii.second >= n)
    {
        pii.first++;
        pii.second -= n;
        n++;
    }
    pii.second++;
    return pii;
}
void init(long long n)
{
    memset(bo2, 0, sizeof(bo2));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            bo2[i][n - 1 + j] = 1;
}
long long calc(long long n)
{
    init(n);
    long long start = (n - 3) * (n - 2) / 2 + 1;
    long long end = (n + 2) * (n + 3) / 2;
    for (long long i = 0; prime[i] * prime[i] <= end; i++)
    {
        long long j = start / prime[i] * prime[i];
        if (j < start) j += prime[i];
        for (; j <= end; j += prime[i])
            bo2[get_coord(j - start, n).first][get_coord(j - start, n).second] = 1;
    }
    long long start0 = start;
    start = (n - 2) * (n - 1) / 2 + 1;
    end = (n + 1) * (n + 2) / 2;
    for (long long i = start; i <= end; i++)
    {
        int x = get_coord(i - start0, n).first;
        int y = get_coord(i - start0, n).second;
        if (bo2[x][y] == 0 || bo2[x][y] == 2)
        {
            int cnt = 0;
            // trick: not only 0 but also 2 is prime!
            for (int j = 0; j < 8; j++)
                if (bo2[x + dir[j][0]][y + dir[j][1]] == 0 || bo2[x + dir[j][0]][y + dir[j][1]] == 2)
                    cnt++;
            if (cnt >= 2)
            {
                bo2[x][y] = 2;
                for (int j = 0; j < 8; j++)
                    if (!bo2[x + dir[j][0]][y + dir[j][1]])
                        bo2[x + dir[j][0]][y + dir[j][1]] = 2;
            }
        }
    }
    long long sum = 0;
    start = (n - 1) * n / 2 + 1;
    end = n * (n + 1) / 2;
    for (long long i = start; i <= end; i++)
    {
        int x = get_coord(i - start0, n).first;
        int y = get_coord(i - start0, n).second;
        if (bo2[x][y] == 2)
        {
            sum += i;
        }
    }
    return sum;
}
int main()
{
    prime_table();
    long long a = 5678027;
    long long b = 7208785;
    long long sum1 = calc(a);
    long long sum2 = calc(b);
    cout << sum1 + sum2 << endl;
    return 0;
}
