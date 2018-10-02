#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 12;
// 和105题条件1的判断相同，首先只需判断数量相等的情况，另外在有序的情况下，第一组的下标对应小于第二组的下标就不用判断了
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
            // 以下判断都是去除重复
            // 第一个集合的第一个数比第二个集合小
            if (vec[0] > vec[vec.size() / 2])
                continue;
            // 第一个集合是升序的
            for (j = 0; j < vec.size() / 2 - 1; j++)
                if (vec[j] > vec[j + 1])
                    break;
            if (j < vec.size() / 2 - 1)
                continue;
            // 第二个集合也是升序的
            for (j = vec.size() / 2; j < vec.size() - 1; j++)
                if (vec[j] > vec[j + 1])
                    break;
            if (j < vec.size() - 1)
                continue;
            // 满足上述条件之后，如果第一个集合的每一个元素都小于第二个集合对应的元素就不用计算，否则要计算
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
