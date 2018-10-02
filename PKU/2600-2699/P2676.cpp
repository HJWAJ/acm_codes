#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
char board[10][10];
bool check(int row, int col, char val)
{
    for (int i = 0; i < 9; i++)
        if (board[row][i] == val && i != col)
            return false;
    for (int i = 0; i < 9; i++)
        if (board[i][col] == val && i != row)
            return false;
    int row1 = row / 3 * 3;
    int col1 = col / 3 * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[row1 + i][col1 + j] == val && row1 + i != row && col1 + j != col)
                return false;
    return true;
}
bool solve(int row, int col)
{
    if (row == 9) return true;
    if (col == 9) return solve(row + 1, 0);
    if (board[row][col] != '0') return solve(row, col + 1);
    for (int i = 1; i <= 9; i++)
        if (check(row, col, i + '0'))
        {
            board[row][col] = i + '0';
            if (solve(row, col + 1)) return true;
            board[row][col] = '0';
        }
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 9; i++) scanf("%s", board[i]);
        solve(0, 0);
        for (int i = 0; i < 9; i++) puts(board[i]);
    }
    return 0;
}
