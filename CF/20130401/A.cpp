#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const char s[45][45]={" Washington ",
" Adams ",
" Jefferson ",
" Madison ",
" Monroe ",
" Adams ",
" Jackson ",
" Van Buren ",
" Harrison ",
" Tyler ",
" Polk ",
" Taylor ",
" Fillmore ",
" Pierce ",
" Buchanan ",
" Lincoln ",
" Johnson ",
" Grant ",
" Hayes ",
" Garfield ",
" Arthur ",
" Cleveland ",
" Harrison ",
" Cleveland ",
" McKinley ",
" Roosevelt ",
" Taft ",
" Wilson ",
" Harding ",
" Coolidge ",
" Hoover ",
" Roosevelt ",
" Truman ",
" Eisenhower ",
" Kennedy ",
" Johnson ",
" Nixon ",
" Ford ",
" Carter ",
" Reagan ",
" Bush ",
" Clinton"};
void print(int n)
{
    int len=strlen(s[n]);
    for(int i=1;i<len-1;i++)printf("%c",s[n][i]);
    puts("");
}
int main()
{
    int n;
    scanf("%d",&n);
    print(n-1);
    return 0;
}
