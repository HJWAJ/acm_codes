#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<sstream>
#include<map>
#include<set>
#include<fstream>
using namespace std;
bool isP(int h,int min)
{
    int tmp;
    tmp=h%10*10+h/10;
    if(tmp==min)return 1;
    return 0;
}
int main()
{
    int h,min;
    scanf("%d:%d",&h,&min);
    do
    {
        if(min!=59)min++;
        else
        {
            min=0;
            if(h!=23)h++;
            else h=0;
        }
    }while(!isP(h,min));
    printf("%02d:%02d\n",h,min);
    return 0;
}
