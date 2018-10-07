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
char s[300];
int getint(char s[], int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res *= 16;
        if (s[i] <= '9') {
            res += s[i] - '0';
        } else {
            res += s[i] - 'A' + 10;
        }
    }
    return res;
}
char tochar(int n) {
    if (n < 10) return '0' + n;
    return 'A' + n - 10;
}
int main() {
    while (scanf("%s", s) && s[0] != '8') {
        int pos = 0, a = 0, b = 0;
        int val;
        while (s[pos] != '8') {
            switch(s[pos]) {
                case '0':
                    val = getint(s + pos + 1, 2);
                    a = getint(s + val, 1);
                    pos += 3;
                    break;
                case '1':
                    val = getint(s + pos + 1, 2);
                    s[val] = tochar(a);
                    pos += 3;
                    break;
                case '2':
                    swap(a, b);
                    pos++;
                    break;
                case '3':
                    val = a + b;
                    a = val % 16;
                    b = val / 16;
                    pos++;
                    break;
                case '4':
                    a++;
                    if (a == 16) a = 0;
                    pos++;
                    break;
                case '5':
                    a--;
                    if (a == -1) a = 15;
                    pos++;
                    break;
                case '6':
                    if (a == 0) {
                        pos = getint(s + pos + 1, 2);
                    } else {
                        pos += 3;
                    }
                    break;
                case '7':
                    pos = getint(s + pos + 1, 2);
                    break;
                default:
                    pos++;
                    break;
            }
        }
        puts(s);
    }
    return 0;
}
