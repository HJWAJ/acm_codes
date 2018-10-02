#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<vector>
using namespace std;
int main()
{
    int n,k,sum,cnt,max=999999999,maxi,i,j,kk;
    char s[15][10100];
    bool bo[10100];
    scanf("%d%d%s",&n,&k,s[11]);
    for(i=0;i<10;i++)
        memmove(s[i],s[11],n);
    for(i=0;i<10;i++)
    {
        sum=cnt=0;
        for(j=0;j<10;j++)
        {
            memset(bo,0,sizeof(bo));
            for(kk=0;kk<n;kk++)
                if(s[i][kk]-(i+'0')==j)
                {
                    bo[kk]=1;
                    cnt++;
                    sum+=j;
                    if(cnt==k)
                    {
                        for(kk=0;kk<n;kk++)
                            if(bo[kk])s[i][kk]='0'+i;
                        goto label;
                    }
                }
            for(kk=n-1;kk>=0;kk--)
                if(s[i][kk]-(i+'0')==-j && !bo[kk])
                {
                    bo[kk]=1;
                    cnt++;
                    sum+=j;
                    if(cnt==k)
                    {
                        for(kk=0;kk<n;kk++)
                            if(bo[kk])s[i][kk]='0'+i;
                        goto label;
                    }
                }
            for(kk=0;kk<n;kk++)
                if(bo[kk])s[i][kk]='0'+i;
            //cout<<cnt<<' ';
            //puts(s[i]);
        }
        label:;
        //printf("%d\n",cnt);
        if(max>sum)
        {
            max=sum;
            maxi=i;
        }
    }
    printf("%d\n",max);
    puts(s[maxi]);
    return 0;
}
