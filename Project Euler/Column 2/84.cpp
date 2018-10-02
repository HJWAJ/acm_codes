#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
const int GO=0;
const int A1=1;
const int CC1=2;
const int A2=3;
const int T1=4;
const int R1=5;
const int B1=6;
const int CH1=7;
const int B2=8;
const int B3=9;
const int JAIL=10;
const int C1=11;
const int U1=12;
const int C2=13;
const int C3=14;
const int R2=15;
const int D1=16;
const int CC2=17;
const int D2=18;
const int D3=19;
const int FP=20;
const int E1=21;
const int CH2=22;
const int E2=23;
const int E3=24;
const int R3=25;
const int F1=26;
const int F2=27;
const int U2=28;
const int F3=29;
const int G2J=30;
const int G1=31;
const int G2=32;
const int CC3=33;
const int G3=34;
const int R4=35;
const int CH3=36;
const int H1=37;
const int T2=38;
const int H2=39;
int cnt[40];
int id[40];
int main()
{
    int i,j,here=GO,dice1,dice2,aa=0,cnt1=0,cnt2=0;
    srand(time(0));
    memset(cnt,0,sizeof(cnt));
    for(i=0;i<40;i++)id[i]=i;
    for(i=0;i<100000;i++)
    {
        dice1=rand()%4+1;
        dice2=rand()%4+1;
        if(dice1==dice2)
        {
            aa++;
            if(aa==3)
            {
                here=JAIL;
                cnt[JAIL]++;
                aa=0;
                continue;
            }
        }
        else aa=0;
        here+=dice1+dice2;
        here%=40;
        cnt[here]++;
        if(here==G2J)
        {
            here=JAIL;
            cnt[JAIL]++;
        }
        else if(here==CC1 || here==CC2 || here==CC3)
        {
            dice1=(cnt1++)%16;
            if(dice1==0)
            {
                here=GO;
                cnt[GO]++;
            }
            else if(dice1==1)
            {
                here=JAIL;
                cnt[JAIL]++;
            }
            else continue;
        }
        else if(here==CH1 || here==CH2 || here==CH3)
        {
            dice1=(cnt2++)%16;
            if(dice1==0)
            {
                here=GO;
                cnt[GO]++;
            }
            else if(dice1==1)
            {
                here=JAIL;
                cnt[JAIL]++;
            }
            else if(dice1==2)
            {
                here=C1;
                cnt[C1]++;
            }
            else if(dice1==3)
            {
                here=E3;
                cnt[E3]++;
            }
            else if(dice1==4)
            {
                here=H2;
                cnt[H2]++;
            }
            else if(dice1==5)
            {
                here=R1;
                cnt[R1]++;
            }
            else if(dice1==6)
            {
                while(here!=R1 && here!=R2 && here!=R3 && here!=R4)
                {
                    here=(here+1)%40;
                    if(!(here!=R1 && here!=R2 && here!=R3 && here!=R4))
                    {
                        cnt[here]++;
                        break;
                    }
                }
            }
            else if(dice1==7)
            {
                while(here!=R1 && here!=R2 && here!=R3 && here!=R4)
                {
                    here=(here+1)%40;
                    if(!(here!=R1 && here!=R2 && here!=R3 && here!=R4))
                    {
                        cnt[here]++;
                        break;
                    }
                }
            }
            else if(dice1==8)
            {
                while(here!=U1 && here!=U2)
                {
                    here=(here+1)%40;
                    if(!(here!=U1 && here!=U2))
                    {
                        cnt[here]++;
                        break;
                    }
                }
            }
            else if(dice1==9)
            {
                here-=3;
                if(here<0)here+=40;
                cnt[here]++;
            }
            else continue;
        }
    }
    for(i=0;i<40;i++)
        for(j=0;j<39-i;j++)
            if(cnt[j]<cnt[j+1])
            {
                swap(cnt[j],cnt[j+1]);
                swap(id[j],id[j+1]);
            }
    for(i=0;i<40;i++)printf("%d %d\n",cnt[i],id[i]);
    return 0;
}
