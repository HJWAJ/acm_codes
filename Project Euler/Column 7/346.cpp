#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
/**
 * repunit ��ʾ��ȫ1��ɵ�����
 * ��Ȼ�κ���n��n-1���ƾ��ɱ�ʾΪ11��
 * ����ת��Ϊ�����е�n��n���÷�n-1���Ʊ�ʾΪȫ1��ɵ�����
 * ���Ƕ��ڽ�λ��b������b^2+b+1,b^3+b^2+b+1...��ȥ�أ������͡�
 */

const long long N = 1000000000000LL;
set<long long> s;
int main()
{
    long long sum = 0, tmp;
    for (long long i = 2; ; i++)
    {
        tmp = i * i + i + 1;
        if (tmp > N) break;
        while (tmp <= N)
        {
            s.insert(tmp);
            tmp *= i;
            tmp++;
        }
    }
    for (set<long long>::iterator it = s.begin(); it != s.end(); ++it) sum += *it;
    cout << sum + 1 << endl;
    return 0;
}
