#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 12;
// ��105������1���ж���ͬ������ֻ���ж�������ȵ���������������������£���һ����±��ӦС�ڵڶ�����±�Ͳ����ж���
int main()
{
    int a[MAX], i, j, cnt = 0;
    vector<int> vec;
    for (i = 0; i < MAX; i++)
        a[i] = i;
    for (i = 0; i < (1 << MAX); i++)
    {
        vec.clear();
        for (j = 0; j < MAX; j++)
            if (i & (1 << j))
                vec.push_back(j);
        if (vec.size() > 2 && (vec.size() & 1) == 0)
        while (next_permutation(vec.begin(), vec.end()))
        {
            // �����ж϶���ȥ���ظ�
            // ��һ�����ϵĵ�һ�����ȵڶ�������С
            if (vec[0] > vec[vec.size() / 2])
                continue;
            // ��һ�������������
            for (j = 0; j < vec.size() / 2 - 1; j++)
                if (vec[j] > vec[j + 1])
                    break;
            if (j < vec.size() / 2 - 1)
                continue;
            // �ڶ�������Ҳ�������
            for (j = vec.size() / 2; j < vec.size() - 1; j++)
                if (vec[j] > vec[j + 1])
                    break;
            if (j < vec.size() - 1)
                continue;
            // ������������֮�������һ�����ϵ�ÿһ��Ԫ�ض�С�ڵڶ������϶�Ӧ��Ԫ�ؾͲ��ü��㣬����Ҫ����
            for (j = 0; j < vec.size() / 2; j++)
                if (vec[j] > vec[j + vec.size() / 2])
                    break;
            if (j < vec.size() / 2)
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
