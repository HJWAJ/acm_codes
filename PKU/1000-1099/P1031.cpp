#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
// dI = I0 * cos(alpha) * dl * h = k * h * ( cos(alpha * dl) / r ) = k * h * d(alpha)
// ->
// I = alpha * k * h
// calc largest angle of polygon to light
const double PI = acos(-1.0);
double x[105], y[105];
double alpha( double x1, double y1, double x2, double y2)
{
    double a = atan2(y1, x1);
    double b = atan2(y2, x2);
    double alpha = a - b;
    if (alpha < -PI) alpha += 2 * PI;
    if (alpha > PI) alpha -= 2 * PI;
    return alpha;
}
int main()
{
    double k, h, mmax = 0, mmin = 0, sum = 0;
    int n;
    scanf("%lf%lf%d", &k, &h, &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", x + i, y + i);
    x[n] = x[0];
    y[n] = y[0];
    for (int i = 0; i < n; i++)
    {
        sum += alpha(x[i], y[i], x[i + 1], y[i + 1]);
        if (sum > mmax) mmax = sum;
        if (sum < mmin) mmin = sum;
        if (mmax - mmin >= 2 * PI) {
            mmax = mmin + 2 * PI;
            break;
        }
    }
    printf("%.2lf\n", (mmax - mmin) * k * h);
    return 0;
}
