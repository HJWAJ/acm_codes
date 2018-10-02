/*

蔡勒公式

蔡勒（Zeller）公式：是一个计算星期的公式。
随便给一个日期，就能用这个公式推算出是星期几。

蔡勒公式如下：
W = [C/4] - 2C + y + [y/4] + [13 * (M+1) / 5] + d - 1
或者是:w=y+[y/4]+[c/4]-2c+[26(m+1)/10]+d-1
公式中的符号含义如下：
w：星期； w 对7 取模得：0-星期日，1-星期一，2-星期二，3-星期三，4-星期四，5-
星期五，6-星期六
c：世纪-1（前两位数）
y：年（后两位数）
m：月（m 大于等于3，小于等于14，即在蔡勒公式中，某年的1、2 月要看作上一年
的13、14 月来计算，比如2003 年1 月1 日要看作2002 年的13 月1 日来计算）
d：日
[]代表取整，即只要整数部分。

*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int w,c,y,m,d,cnt=0;
    c=20;d=1;
    for(y=1900;y<2000;y++)
        for(m=3;m<15;m++)
        {
            w=(c/4-2*c+y+y/4+13*(m+1)/5+d-1)%7;
            if(!w)cnt++;
        }
    printf("%d\n",cnt);
    return 0;
}
