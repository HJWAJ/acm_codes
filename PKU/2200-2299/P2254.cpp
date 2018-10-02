#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define esp 1e-10
using namespace std;

const double pi = 3.141592653589793 / 180.0;
const double r = 6378.0;

int ok(double a) {
    if (fabs(a) < esp) return 0;
    if (a > 0) return 1;
    return -1;
}

struct node{
    char str[33];
    double ns, ew;
} input[110];
int ct;
char s1[33], s2[33];

double solve(double x1, double y1, double x2, double y2) {
    double a, ans;
    a = sin(x1 * pi) * sin(x2 * pi) + cos(x1 * pi) * cos(x2 * pi) * cos((y1 - y2) * pi);
    if (ok(a + 1.0) == -1) a = -1.0;
    else if(ok(a - 1.0) == 1) a = 1.0;
    ans = r * acos(a);
    return ans;
}

int main() {
    int i;
    ct = 0;
        while (1) {
            scanf("%s%lf%lf", input[ct].str, &input[ct].ns, &input[ct].ew);
            ct++;
            if (input[ct - 1].str[0] == '#') break;
        }
        ct--;
        while (1) {
            scanf("%s%s", s1, s2);
            if (s1[0] == '#') break;
            int a, b;
            for (i = 0; i < ct; i++) if (strcmp(s1, input[i].str) == 0) break;
            a = i;
            for (i = 0; i < ct; i++) if (strcmp(s2, input[i].str) == 0) break;
            b = i;
            printf("%s - %s\n", s1, s2);
            if (a == ct || b == ct) printf("Unknown\n\n");
            else printf("%.0lf km\n\n", solve(input[a].ns, input[a].ew, input[b].ns, input[b].ew));
        }
    return 0;
}
