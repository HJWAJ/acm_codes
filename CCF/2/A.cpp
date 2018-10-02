#include <iostream>
using namespace std;
int a[505];
int main()
{
    int n, cnt;
    while (scanf("%d", &n) != EOF) {
        cnt = 0;
        for (int i = 0; i < n; i++) scanf("%d", a + i);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] == -a[j])
                    cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}