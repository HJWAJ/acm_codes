#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
#include<windows.h>
using namespace std;
int a[10]={1,2,3,4,5,6,7,8,9,10};
int b[10];
char s[21],ans[21];
int main()
{
    int cnt=0;
    while(cnt<3628800)
    {
        cnt++;
        next_permutation(a,a+10);
        if(a[1]==10 || a[2]==10 || a[4]==10 || a[6]==10 || a[8]==10)continue;
        if( !(a[0]+a[1]+a[2]==a[3]+a[2]+a[8] && a[3]+a[2]+a[8]==a[6]+a[8]+a[9] && a[6]+a[8]+a[9]==a[4]+a[6]+a[7] && a[4]+a[6]+a[7]==a[1]+a[4]+a[5]) )continue;
        if(a[3]>a[0] || a[3]>a[5] || a[3]>a[7] || a[3]>a[9])continue;
        memset(s,0,sizeof(s));
        sprintf(s+strlen(s),"%d",a[3]);sprintf(s+strlen(s),"%d",a[2]);sprintf(s+strlen(s),"%d",a[8]);
        sprintf(s+strlen(s),"%d",a[9]);sprintf(s+strlen(s),"%d",a[8]);sprintf(s+strlen(s),"%d",a[6]);
        sprintf(s+strlen(s),"%d",a[7]);sprintf(s+strlen(s),"%d",a[6]);sprintf(s+strlen(s),"%d",a[4]);
        sprintf(s+strlen(s),"%d",a[5]);sprintf(s+strlen(s),"%d",a[4]);sprintf(s+strlen(s),"%d",a[1]);
        sprintf(s+strlen(s),"%d",a[0]);sprintf(s+strlen(s),"%d",a[1]);sprintf(s+strlen(s),"%d",a[2]);
        if(strcmp(s,ans)==1)
        {
            strcpy(ans,s);
            for(int i=0;i<10;i++)b[i]=a[i];
        }
    }
    puts(ans);
    for(int i=0;i<10;i++)cout<<b[i]<<' ';
    cout<<endl;
    return 0;
}
