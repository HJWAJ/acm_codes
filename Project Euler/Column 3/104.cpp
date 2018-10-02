#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

/**
 * �������9λ����1~9�ģ�ֻ��Ҫģ��10^9��
 * �ٶ���Щ�ֱ���֤ǰ9λ
 * ��֤��ʽ��
 * fn = (1.0/ sqrt(5)) * (((1 + sqrt(5))/2) ^ n - ((1 - sqrt(5))/2) ^ n) ��n�㹻���ʱ���벿��������С��
 * lg fn = nlg((1 + sqrt(5))/2) - lg sqrt(5)
 * ������a = c1 * 10^c2��lg a = c2���������֣� + lg c1��С�����֣�
 * ����ֻҪ��lg fn��С�����֣���Ϊc��Ȼ��10^c���������־������λ
 * 10^c * 10^8���������־���ǰ9λ
 */
const int MOD = 1000000000;
bool ok_last(int n)
{
    char s[10];
    sprintf(s, "%d", n);
    sort(s, s + 9);
    for (int i = 0; i < 9; i++)
        if (s[i] - '0' != i + 1)
            return false;
    return true;
}
bool ok_prev(int n)
{
    double lgf = n * log10((1 + sqrt(5.0)) / 2) - log10(sqrt(5.0));
    int ilgf = lgf;
    double flgf = lgf - ilgf;
    int num = floor(pow(10, flgf) * 100000000 + 0.5);
    return ok_last(num);
}
int main()
{
    int i = 3, a = 1, b = 1, c;
    while(1)
    {
        c = (a + b) % MOD;
        if (ok_last(c) && ok_prev(i))
        {
            cout << i << endl;
            break;
        }
        a = b;
        b = c;
        i++;
    }
	return 0;
}
