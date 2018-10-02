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
#define PI acos(-1)
#define eqs 0.01
double gcd(double a,double b)
{
    return a < eqs ? b : gcd(fmod(b,a),a);
}
int main()
{
    double x1 , y1 , x2 , y2 , x3 , y3 ;
    double a , b , c , p , s , r , k ;
    double A , B , C ;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) ;
    a = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) ;
    b = sqrt( (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) ) ;
    c = sqrt( (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3) ) ;
    p = ( a + b + c ) / 2.0 ;
    s = sqrt( p * (p-a) * (p-b) * (p-c) ) ;
    r = a * b * c / ( 4 * s ) ;
    if( a > c )
    {
        k = a ;
        a = c ;
        c = k ;
    }
    if( b > c )
    {
        k = b ;
        b = c ;
        c = k ;
    }
    A = 2 * asin(a/(2*r)) ;
    B = 2 * asin(b/(2*r)) ;
    C = 2 * PI - A - B ;
    p = gcd(A,B);
    p = gcd(p,C) ;
    printf("%.6lf\n", (PI*r*r*sin(p))/p ) ;
    return 0;
}
