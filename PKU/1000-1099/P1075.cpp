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
using namespace std;
struct Student
{
    int region;
    int score;
    int state;
    int currentChoice;
    bool done;
    vector<int> schoolIds;
} students[155];
struct StudentPtr
{
    int id;
    int region;
    bool operator < (const StudentPtr b) const
    {
        if (students[id].region == region && students[b.id].region == b.region) return students[id].score > students[b.id].score;
        if (students[id].region == region) return students[id].score * 10 > students[b.id].score * 7;
        if (students[b.id].region == b.region) return students[id].score * 7 >= students[b.id].score * 10;
        return students[id].score > students[b.id].score;
    }
};
struct School
{
    int region;
    int cnt;
    priority_queue<StudentPtr> students;
} schools[155];
void init(int n, int m)
{
    int k, tmp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &students[i].region, &students[i].score, &k);
        students[i].schoolIds.clear();
        while (k--)
        {
            scanf("%d", &tmp);
            students[i].schoolIds.push_back(tmp);
        }
        students[i].state = 0;
        students[i].currentChoice = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &schools[i].region, &schools[i].cnt);
        while (!schools[i].students.empty()) schools[i].students.pop();
    }
}
int main()
{
    int t, tt = 0, n, m;
    scanf("%d", &t);
    while (t--)
    {
        tt++;
        scanf("%d%d", &n, &m);
        init(n, m);
        int unstable = n;
        while (unstable > 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (students[i].state != 0) continue;
                if (students[i].currentChoice == students[i].schoolIds.size())
                {
                    students[i].state = -1;
                    unstable--;
                    continue;
                }
                int schoolId = students[i].schoolIds[students[i].currentChoice];
                students[i].state = schoolId;
                StudentPtr stuPtr;
                stuPtr.id = i;
                stuPtr.region = schools[schoolId].region;
                schools[schoolId].students.push(stuPtr);
                unstable--;
                students[i].currentChoice++;
            }
            for (int i = 1; i <= m; i++)
            {
                while (schools[i].students.size() > schools[i].cnt)
                {
                    StudentPtr stuPtr = schools[i].students.top();
                    schools[i].students.pop();
                    students[stuPtr.id].state = 0;
                    unstable++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (students[i].state == -1) puts("not accepted");
            else printf("%d\n", students[i].state);
        }
        puts("");
    }
    return 0;
}
