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
    int n,i,j,cnt1,cnt2,c1,c2;
    char s[5][5];
    scanf("%d",&n);
    while(n--)
    {
        cnt1=cnt2=0;
        for(i=0;i<3;i++)scanf("%s",s[i]);
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                if(s[i][j]=='X')cnt1++;
                if(s[i][j]=='O')cnt2++;
            }
        if(cnt1!=cnt2 && cnt1-cnt2!=1)
        {
            puts("no");
            continue;
        }
        if(s[0][0]==s[0][1] && s[0][1]==s[0][2] && s[0][2]==s[1][0] && s[1][0]==s[2][0])
        {
            puts("yes");
            continue;
        }
        if(s[0][0]==s[0][1] && s[0][1]==s[0][2] && s[0][2]==s[1][1] && s[1][1]==s[2][1])
        {
            puts("yes");
            continue;
        }
        if(s[0][0]==s[0][1] && s[0][1]==s[0][2] && s[0][2]==s[1][2] && s[1][2]==s[2][2])
        {
            puts("yes");
            continue;
        }
        if(s[1][0]==s[1][1] && s[1][1]==s[1][2] && s[1][2]==s[0][0] && s[0][0]==s[2][0])
        {
            puts("yes");
            continue;
        }
        if(s[1][0]==s[1][1] && s[1][1]==s[1][2] && s[1][2]==s[0][1] && s[0][1]==s[2][1])
        {
            puts("yes");
            continue;
        }
        if(s[1][0]==s[1][1] && s[1][1]==s[1][2] && s[1][2]==s[0][2] && s[0][2]==s[2][2])
        {
            puts("yes");
            continue;
        }
        if(s[2][0]==s[2][1] && s[2][1]==s[2][2] && s[2][2]==s[0][0] && s[0][0]==s[1][0])
        {
            puts("yes");
            continue;
        }
        if(s[2][0]==s[2][1] && s[2][1]==s[2][2] && s[2][2]==s[0][1] && s[0][1]==s[1][1])
        {
            puts("yes");
            continue;
        }
        if(s[2][0]==s[2][1] && s[2][1]==s[2][2] && s[2][2]==s[0][2] && s[0][2]==s[1][2])
        {
            puts("yes");
            continue;
        }
        if(s[0][0]==s[1][1] && s[1][1]==s[2][2] && s[2][2]==s[0][2] && s[0][2]==s[2][0])
        {
            puts("yes");
            continue;
        }
        c1=cnt1;c2=cnt2;
        cnt1=cnt2=0;
        for(i=0;i<3;i++)
        {
            if(s[i][0]==s[i][1] && s[i][1]==s[i][2])
            {
                if(s[i][0]=='X')cnt1++;
                else if(s[i][0]=='O')cnt2++;
            }
            if(s[0][i]==s[1][i] && s[1][i]==s[2][i])
            {
                if(s[0][i]=='X')cnt1++;
                else if(s[0][i]=='O')cnt2++;
            }
        }
        if(s[0][0]==s[1][1] && s[1][1]==s[2][2])
        {
            if(s[0][0]=='X')cnt1++;
            else if(s[0][0]=='O')cnt2++;
        }
        if(s[0][2]==s[1][1] && s[1][1]==s[2][0])
        {
            if(s[2][0]=='X')cnt1++;
            else if(s[2][0]=='O')cnt2++;
        }
        if(cnt1+cnt2>=2)
        {
            puts("no");
            continue;
        }
        if(cnt1==1 && c1-c2!=1)
        {
            puts("no");
            continue;
        }
        if(cnt2==1 && c1!=c2)
        {
            puts("no");
            continue;
        }
        puts("yes");
    }
	return 0;
}
