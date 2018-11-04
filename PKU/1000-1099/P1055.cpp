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
char str[55];
map<string, int> bundle1;
map<string, int> bundle2;
vector<string> invalid;
set<string> repeated_invalid;
bool valid(string s) {
    if (s.length() != 5) return false;
    bool all0 = true;
    bool alld = true;
    for (int i = 0; i < 5; i++) {
        if (s[i] != '0') all0 = false;
        if (s[i] < '0' || s[i] > '9') alld = false;
    }
    return !all0 && alld;
}
int main() {
    // freopen("in", "r", stdin);
    string s;
    int total = 0, bundle_cnt = 0;
    while (scanf("%s", str) != EOF) {
        s = str;
        if (valid(s)) {
            total++;
            bundle1[s]++;
            bundle2[s.substr(0, 3)]++;
        } else {
            if (repeated_invalid.find(s) == repeated_invalid.end()) {
                invalid.push_back(s);
                repeated_invalid.insert(s);
            }
        }
    }
    puts("ZIP         LETTERS     BUNDLES");
    puts("");
    for (map<string, int>::iterator it = bundle1.begin(); it != bundle1.end(); it++) {
        if (it->second >= 10) {
            int bundles = it->second / 15 + ((it->second % 15) ? 1 : 0);
            bundle_cnt += bundles;
            printf("%s% 12d% 12d\n", (it->first).c_str(), it->second, bundles);
            bundle2[(it->first).substr(0, 3)] -= it->second;
        }
    }
    puts("");
    for (map<string, int>::iterator it = bundle2.begin(); it != bundle2.end(); it++) {
        if (it->second >= 10) {
            int bundles = it->second / 15 + ((it->second % 15) ? 1 : 0);
            bundle_cnt += bundles;
            printf("%sxx% 12d% 12d\n", (it->first).c_str(), it->second, bundles);
        }
    }
    puts("");
    for (map<string, int>::iterator it = bundle1.begin(); it != bundle1.end(); it++) {
        if (it->second < 10 && bundle2[(it->first).substr(0, 3)] < 10) {
            printf("%s% 12d% 12d\n", (it->first).c_str(), it->second, 0);
        }
    }
    puts("");
    printf("TOTALS% 11d% 12d\n", total, bundle_cnt);
    puts("");
    puts("INVALID ZIP CODES");
    puts("");
    for (int i = 0; i < invalid.size(); i++) {
        puts(invalid[i].c_str());
    }
    return 0;
}