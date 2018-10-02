#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
// ��x = n + k, y = 1/n - 1/(n+k) = k/n(n+k)
// ����k����n^2����1<=k<=n
// ����k�ĸ�������n^2���ӵĸ���/2+1
// ������ʵ�n^2����n=p1^k1 * p2^k2 * ... *pn^kn��n^2����������Ϊ(2k1+1)(2k2+1)...(2kn+1)
// �����>1000����n^2���Ӹ���>1999������3^7=2187������pn<=17, n<7��
// ���⣬pi < pi+1, ki >= ki+1������ö�����������
// �жϴ�Сʱ��log��
// 110��3^15 > 8000000������pn<=47, n<15
const int MAX = 7;
const long long MAX_NUM = 2000;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int max_exp[] = {1000, 22, 6, 3, 2, 2, 1};
void print(int exp[], int n)
{
    for (int i = 0; i < n; i++)
        cout << exp[i] << ' ';
    cout << endl;
}
int calc_factor(int exp[])
{
    long long res = 1;
    for (int i = 0; ; i++)
    {
        res *= (exp[i] * 2 + 1);
        if (res >= MAX_NUM)
        {
            return i + 1;
        }
    }
}
double calc(int exp[], int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
        res += exp[i] * log(prime[i] * 1.0);
    return res;
}
long long calc_ans(int exp[], int n)
{
    long long res = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < exp[i]; j++)
        {
            res *= prime[i];
        }
    }
    return res;
}
void update(int exp[], int n, int min_exp[])
{
    for (int i = 0; i < n; i++)
        min_exp[i] = exp[i];
}
void dfs(int exp[], int n, int i, int min_exp[], int &min_n, double &min_num)
{
    int tmp_n;
    double tmp;
    if (i == n)
    {
        tmp_n = calc_factor(exp);
        tmp = calc(exp, tmp_n);
        if (tmp < min_num)
        {
            min_n = tmp_n;
            min_num = tmp;
            update(exp, min_n, min_exp);
        }
        return;
    }
    else if (i == 0)
    {
        for (int j = 1; j <= max_exp[i]; j++)
        {
            exp[i] = j;
            dfs(exp, n, i + 1, min_exp, min_n, min_num);
        }
    }
    for (int j = 1; j <= max_exp[i] && j <= exp[i - 1]; j++)
    {
        exp[i] = j;
        dfs(exp, n, i + 1, min_exp, min_n, min_num);
    }
}
int main()
{
    int exp[MAX], min_exp[MAX], min_n;
    double min_num = 1.0;
    for (int i = 0 ; i < MAX; i++)
    {
        exp[i] = 1;
        min_exp[i] = 1;
        min_num += log(prime[i] * 1.0);
    }
    min_n = MAX;
    dfs(exp, MAX, 0, min_exp, min_n, min_num);
    cout << calc_ans(min_exp, min_n) << endl;
    return 0;
}
