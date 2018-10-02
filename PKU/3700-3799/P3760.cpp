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
using namespace std;
const char names[5][10]= {"dragon", "ninja", "iceman", "lion", "wolf"};
int maxhp[5],maxop[5];
const int redproduce[5]= {2,3,4,1,0}; //red produce sort
const int blueproduce[5]= {3,0,1,2,4}; //blue produce sort
char outputstring[25][5005];//place occured
bool shouldoutput[25];//should output string
struct city
{
    int flag;//0--not captured   1--red captured   2--blue captured
    int hp;//hp in the city
    bool redhere,bluehere;//red/blue warriors here
    int redid,blueid;//warrior id
    int redwin,bluewin;
} cities[25];
int cityN;
struct warrior
{
    char name[10];
    int hp;
    int op;
    int place;//-1--start   -2--end   else city
    bool state;//1--alive   0--dead
    bool steps;//1--will finish second step
    int kill;//1--will finish second kill
    bool win;//should be praised
} bluewarriors[105],redwarriors[105];
struct center
{
    int producenum;//number of warroirs produced
    int hp;
    int enemy;//number of enemy here
    int tmphp;
} redcenter,bluecenter;
int time;//time now
int maxtime;//time ends
bool gameover;//game ends
void init()
{
    int i;
    scanf("%d%d%d",&redcenter.hp,&cityN,&maxtime);
    bluecenter.hp=redcenter.hp;
    time=0;
    bluecenter.producenum=redcenter.producenum=0;
    bluecenter.enemy=redcenter.enemy=0;
    gameover=0;
    memset(cities,0,sizeof(cities));
    memset(redwarriors,0,sizeof(redwarriors));
    memset(bluewarriors,0,sizeof(bluewarriors));
    for(i=0; i<5; i++)scanf("%d",maxhp+i);
    for(i=0; i<5; i++)scanf("%d",maxop+i);
}
void output()
{
    int i;
    for(i=0; i<=cityN+1; i++)
        if(shouldoutput[i])
            printf("%s",outputstring[i]);
}
void producewarriors()
{
    int redw=redproduce[(redcenter.producenum)%5];
    int bluew=blueproduce[(bluecenter.producenum)%5];
    memset(shouldoutput,0,sizeof(shouldoutput));
    memset(outputstring,0,sizeof(outputstring));
    if(redcenter.hp>=maxhp[redw])
    {
        strcpy(redwarriors[redcenter.producenum].name,names[redw]);
        redwarriors[redcenter.producenum].hp=maxhp[redw];
        redwarriors[redcenter.producenum].op=maxop[redw];
        redwarriors[redcenter.producenum].place=-1;
        redwarriors[redcenter.producenum].state=1;
        redcenter.producenum++;
        redcenter.hp-=maxhp[redw];
        shouldoutput[0]=1;
        sprintf(outputstring[0],
                "%03d:%02d red %s %d born\n",
                time/60,time%60,names[redw],redcenter.producenum);
    }
    if(bluecenter.hp>=maxhp[bluew])
    {
        strcpy(bluewarriors[bluecenter.producenum].name,names[bluew]);
        bluewarriors[bluecenter.producenum].hp=maxhp[bluew];
        bluewarriors[bluecenter.producenum].op=maxop[bluew];
        bluewarriors[bluecenter.producenum].place=-1;
        bluewarriors[bluecenter.producenum].state=1;
        bluecenter.producenum++;
        bluecenter.hp-=maxhp[bluew];
        shouldoutput[cityN+1]=1;
        sprintf(outputstring[cityN+1],
                "%03d:%02d blue %s %d born\n",
                time/60,time%60,names[bluew],bluecenter.producenum);
    }
}
void move(int i,int center)//center 0:red 1:blue
{
    if(center==0)
    {
        if(redwarriors[i].place==-1)
        {
            redwarriors[i].place=0;
            cities[0].redhere=1;
            cities[0].redid=i;
            redwarriors[i].steps^=1;
            if(!strcmp(redwarriors[i].name,"iceman") && !redwarriors[i].steps)
            {
                if(redwarriors[i].hp>9)redwarriors[i].hp-=9;
                else redwarriors[i].hp=1;
                redwarriors[i].op+=20;
            }
            shouldoutput[1]=1;
            sprintf(outputstring[1]+strlen(outputstring[1]),
                    "%03d:%02d red %s %d marched to city 1 with %d elements and force %d\n",
                    time/60,time%60,names[redproduce[i%5]],i+1,redwarriors[i].hp,redwarriors[i].op);
        }
        else if(redwarriors[i].place==cityN-1)
        {
            cities[cityN-1].redhere=0;
            redwarriors[i].place=-2;
            redwarriors[i].steps^=1;
            if(!strcmp(redwarriors[i].name,"iceman") && !redwarriors[i].steps)
            {
                if(redwarriors[i].hp>9)redwarriors[i].hp-=9;
                else redwarriors[i].hp=1;
                redwarriors[i].op+=20;
            }
            shouldoutput[cityN+1]=1;
            sprintf(outputstring[cityN+1]+strlen(outputstring[cityN+1]),
                    "%03d:%02d red %s %d reached blue headquarter with %d elements and force %d\n",
                    time/60,time%60,names[redproduce[i%5]],i+1,redwarriors[i].hp,redwarriors[i].op);
            redwarriors[i].state=0;
            bluecenter.enemy++;
            if(bluecenter.enemy==2)
            {
                gameover=1;
                shouldoutput[cityN+1]=1;
                sprintf(outputstring[cityN+1]+strlen(outputstring[cityN+1]),
                        "%03d:%02d blue headquarter was taken\n",
                        time/60,time%60);
            }
        }
        else//normal city forward
        {
            cities[redwarriors[i].place].redhere=0;
            redwarriors[i].place++;
            redwarriors[i].steps^=1;
            cities[redwarriors[i].place].redhere=1;
            cities[redwarriors[i].place].redid=i;
            if(!strcmp(redwarriors[i].name,"iceman") && !redwarriors[i].steps)
            {
                if(redwarriors[i].hp>9)redwarriors[i].hp-=9;
                else redwarriors[i].hp=1;
                redwarriors[i].op+=20;
            }
            shouldoutput[redwarriors[i].place+1]=1;
            sprintf(outputstring[redwarriors[i].place+1]+strlen(outputstring[redwarriors[i].place+1]),
                    "%03d:%02d red %s %d marched to city %d with %d elements and force %d\n",
                    time/60,time%60,names[redproduce[i%5]],i+1,redwarriors[i].place+1,redwarriors[i].hp,redwarriors[i].op);
        }
    }
    else//center==1
    {
        if(bluewarriors[i].place==-1)
        {
            bluewarriors[i].place=cityN-1;
            bluewarriors[i].steps^=1;
            cities[cityN-1].bluehere=1;
            cities[cityN-1].blueid=i;
            if(!strcmp(bluewarriors[i].name,"iceman") && !bluewarriors[i].steps)
            {
                if(bluewarriors[i].hp>9)bluewarriors[i].hp-=9;
                else bluewarriors[i].hp=1;
                bluewarriors[i].op+=20;
            }
            shouldoutput[cityN]=1;
            sprintf(outputstring[cityN]+strlen(outputstring[cityN]),
                    "%03d:%02d blue %s %d marched to city %d with %d elements and force %d\n",
                    time/60,time%60,names[blueproduce[i%5]],i+1,cityN,bluewarriors[i].hp,bluewarriors[i].op);
        }
        else if(bluewarriors[i].place==0)
        {
            cities[0].bluehere=0;
            bluewarriors[i].place=-2;
            bluewarriors[i].steps^=1;
            if(!strcmp(bluewarriors[i].name,"iceman") && !bluewarriors[i].steps)
            {
                if(bluewarriors[i].hp>9)bluewarriors[i].hp-=9;
                else bluewarriors[i].hp=1;
                bluewarriors[i].op+=20;
            }
            shouldoutput[0]=1;
            sprintf(outputstring[0]+strlen(outputstring[0]),
                    "%03d:%02d blue %s %d reached red headquarter with %d elements and force %d\n",
                    time/60,time%60,names[blueproduce[i%5]],i+1,bluewarriors[i].hp,bluewarriors[i].op);
            bluewarriors[i].state=0;
            redcenter.enemy++;
            if(redcenter.enemy==2)
            {
                gameover=1;
                shouldoutput[0]=1;
                sprintf(outputstring[0]+strlen(outputstring[0]),
                        "%03d:%02d red headquarter was taken\n",
                        time/60,time%60);
            }
        }
        else//normal city forward
        {
            cities[bluewarriors[i].place].bluehere=0;
            bluewarriors[i].place--;
            bluewarriors[i].steps^=1;
            cities[bluewarriors[i].place].bluehere=1;
            cities[bluewarriors[i].place].blueid=i;
            if(!strcmp(bluewarriors[i].name,"iceman") && !bluewarriors[i].steps)
            {
                if(bluewarriors[i].hp>9)bluewarriors[i].hp-=9;
                else bluewarriors[i].hp=1;
                bluewarriors[i].op+=20;
            }
            shouldoutput[bluewarriors[i].place+1]=1;
            sprintf(outputstring[bluewarriors[i].place+1]+strlen(outputstring[bluewarriors[i].place+1]),
                    "%03d:%02d blue %s %d marched to city %d with %d elements and force %d\n",
                    time/60,time%60,names[blueproduce[i%5]],i+1,bluewarriors[i].place+1,bluewarriors[i].hp,bluewarriors[i].op);
        }
    }
}
void warriorsmove()
{
    int i;
    memset(shouldoutput,0,sizeof(shouldoutput));
    memset(outputstring,0,sizeof(outputstring));
    for(i=0; i<redcenter.producenum; i++)
        if(redwarriors[i].state)
            move(i,0);
    for(i=0; i<bluecenter.producenum; i++)
        if(bluewarriors[i].state)
            move(i,1);
}
void producehp()
{
    int i;
    memset(shouldoutput,0,sizeof(shouldoutput));
    memset(outputstring,0,sizeof(outputstring));
    for(i=0; i<cityN; i++)
        cities[i].hp+=10;
}
void gethp()
{
    int i;
    memset(shouldoutput,0,sizeof(shouldoutput));
    memset(outputstring,0,sizeof(outputstring));
    for(i=0; i<cityN; i++)
    {
        if(cities[i].bluehere && !cities[i].redhere)
        {
            shouldoutput[i+1]=1;
            sprintf(outputstring[i+1]+strlen(outputstring[i+1]),
                    "%03d:%02d blue %s %d earned %d elements for his headquarter\n",
                    time/60,time%60,bluewarriors[cities[i].blueid].name,cities[i].blueid+1,cities[i].hp);
            bluecenter.hp+=cities[i].hp;
            cities[i].hp=0;
        }
        else if(!cities[i].bluehere && cities[i].redhere)
        {
            shouldoutput[i+1]=1;
            sprintf(outputstring[i+1]+strlen(outputstring[i+1]),
                    "%03d:%02d red %s %d earned %d elements for his headquarter\n",
                    time/60,time%60,redwarriors[cities[i].redid].name,cities[i].redid+1,cities[i].hp);
            redcenter.hp+=cities[i].hp;
            cities[i].hp=0;
        }
    }
}
void attack(int cityid,int attacker,int defender,int flag)//flag 0:red attack 1:blue attack
{
    int tmp;
    if(flag==0)//red attack
    {
        shouldoutput[cityid+1]=1;
        sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                "%03d:%02d red %s %d attacked blue %s %d in city %d with %d elements and force %d\n",
                time/60,time%60,names[redproduce[attacker%5]],attacker+1,names[blueproduce[defender%5]],defender+1,cityid+1,redwarriors[attacker].hp,redwarriors[attacker].op);
        tmp=bluewarriors[defender].hp;
        bluewarriors[defender].hp-=redwarriors[attacker].op;
        if(bluewarriors[defender].hp<=0)//kill
        {
            shouldoutput[cityid+1]=1;
            sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                    "%03d:%02d blue %s %d was killed in city %d\n",
                    time/60,time%60,names[blueproduce[defender%5]],defender+1,cityid+1);
            redcenter.tmphp+=cities[cityid].hp;
            if(cities[cityid].redhere && !strcmp(redwarriors[cities[cityid].redid].name,"dragon") && !flag)
            {
                shouldoutput[cityid+1]=1;
                sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                        "%03d:%02d red dragon %d yelled in city %d\n",
                        time/60,time%60,cities[cityid].redid+1,cityid+1);
            }
            sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                    "%03d:%02d red %s %d earned %d elements for his headquarter\n",
                    time/60,time%60,names[redproduce[attacker%5]],attacker+1,cities[cityid].hp);
            cities[cityid].hp=0;
            redwarriors[attacker].win=1;
            redwarriors[attacker].kill+=1;
            if(!strcmp(redwarriors[attacker].name,"wolf") && !(redwarriors[attacker].kill&1) && redwarriors[attacker].kill)
            {
                redwarriors[attacker].hp*=2;
                redwarriors[attacker].op*=2;
            }
            if(!strcmp(bluewarriors[defender].name,"lion"))redwarriors[attacker].hp+=tmp;
            bluewarriors[defender].state=0;
            cities[cityid].bluehere=0;
            cities[cityid].redwin++;
            cities[cityid].bluewin=0;
            if(cities[cityid].redwin==2 && cities[cityid].flag!=1)
            {
                cities[cityid].flag=1;
                shouldoutput[cityid+1]=1;
                sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                        "%03d:%02d red flag raised in city %d\n",
                        time/60,time%60,cityid+1);
            }
        }
        else//fight back
        {
            if(strcmp(bluewarriors[defender].name,"ninja"))
            {
                shouldoutput[cityid+1]=1;
                sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                        "%03d:%02d blue %s %d fought back against red %s %d in city %d\n",
                        time/60,time%60,names[blueproduce[defender%5]],defender+1,names[redproduce[attacker%5]],attacker+1,cityid+1);
                tmp=redwarriors[attacker].hp;
                redwarriors[attacker].hp-=bluewarriors[defender].op/2;
                if(redwarriors[attacker].hp<=0)
                {
                    shouldoutput[cityid+1]=1;
                    sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                            "%03d:%02d red %s %d was killed in city %d\n",
                            time/60,time%60,names[redproduce[attacker%5]],attacker+1,cityid+1);
                    bluecenter.tmphp+=cities[cityid].hp;
                    sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                            "%03d:%02d blue %s %d earned %d elements for his headquarter\n",
                            time/60,time%60,names[blueproduce[defender%5]],defender+1,cities[cityid].hp);
                    cities[cityid].hp=0;
                    bluewarriors[defender].win=1;
                    if(!strcmp(redwarriors[attacker].name,"lion"))bluewarriors[defender].hp+=tmp;
                    redwarriors[attacker].state=0;
                    cities[cityid].redhere=0;
                    cities[cityid].bluewin++;
                    cities[cityid].redwin=0;
                    if(cities[cityid].bluewin==2 && cities[cityid].flag!=2)
                    {
                        cities[cityid].flag=2;
                        shouldoutput[cityid+1]=1;
                        sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                                "%03d:%02d blue flag raised in city %d\n",
                                time/60,time%60,cityid+1);
                    }
                }
                else
                {
                    if(cities[cityid].redhere && !strcmp(redwarriors[cities[cityid].redid].name,"dragon") && !flag)
                    {
                        shouldoutput[cityid+1]=1;
                        sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                                "%03d:%02d red dragon %d yelled in city %d\n",
                                time/60,time%60,cities[cityid].redid+1,cityid+1);
                    }
                    cities[cityid].bluewin=cities[cityid].redwin=0;
                }
            }
            else
            {
                if(cities[cityid].redhere && !strcmp(redwarriors[cities[cityid].redid].name,"dragon") && !flag)
                {
                    shouldoutput[cityid+1]=1;
                    sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                            "%03d:%02d red dragon %d yelled in city %d\n",
                            time/60,time%60,cities[cityid].redid+1,cityid+1);
                }
                cities[cityid].bluewin=cities[cityid].redwin=0;
            }
        }
    }
    else//blue attack
    {
        shouldoutput[cityid+1]=1;
        sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                "%03d:%02d blue %s %d attacked red %s %d in city %d with %d elements and force %d\n",
                time/60,time%60,names[blueproduce[attacker%5]],attacker+1,names[redproduce[defender%5]],defender+1,cityid+1,bluewarriors[attacker].hp,bluewarriors[attacker].op);
        tmp=redwarriors[defender].hp;
        redwarriors[defender].hp-=bluewarriors[attacker].op;
        if(redwarriors[defender].hp<=0)//kill
        {
            shouldoutput[cityid+1]=1;
            sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                    "%03d:%02d red %s %d was killed in city %d\n",
                    time/60,time%60,names[redproduce[defender%5]],defender+1,cityid+1);
            bluecenter.tmphp+=cities[cityid].hp;
            if(cities[cityid].bluehere && !strcmp(bluewarriors[cities[cityid].blueid].name,"dragon") && flag)
            {
                shouldoutput[cityid+1]=1;
                sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                        "%03d:%02d blue dragon %d yelled in city %d\n",
                        time/60,time%60,cities[cityid].blueid+1,cityid+1);
            }
            sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                    "%03d:%02d blue %s %d earned %d elements for his headquarter\n",
                    time/60,time%60,names[blueproduce[attacker%5]],attacker+1,cities[cityid].hp);
            cities[cityid].hp=0;
            bluewarriors[attacker].win=1;
            bluewarriors[attacker].kill+=1;
            if(!strcmp(bluewarriors[attacker].name,"wolf") && !(bluewarriors[attacker].kill&1) && bluewarriors[attacker].kill)
            {
                bluewarriors[attacker].hp*=2;
                bluewarriors[attacker].op*=2;
            }
            if(!strcmp(redwarriors[defender].name,"lion"))bluewarriors[attacker].hp+=tmp;
            redwarriors[defender].state=0;
            cities[cityid].redhere=0;
            cities[cityid].bluewin++;
            cities[cityid].redwin=0;
            if(cities[cityid].bluewin==2 && cities[cityid].flag!=2)
            {
                cities[cityid].flag=2;
                shouldoutput[cityid+1]=1;
                sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                        "%03d:%02d blue flag raised in city %d\n",
                        time/60,time%60,cityid+1);
            }
        }
        else//fight back
        {
            if(strcmp(redwarriors[defender].name,"ninja"))
            {
                shouldoutput[cityid+1]=1;
                sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                        "%03d:%02d red %s %d fought back against blue %s %d in city %d\n",
                        time/60,time%60,names[redproduce[defender%5]],defender+1,names[blueproduce[attacker%5]],attacker+1,cityid+1);
                tmp=bluewarriors[attacker].hp;
                bluewarriors[attacker].hp-=redwarriors[defender].op/2;
                if(bluewarriors[attacker].hp<=0)
                {
                    shouldoutput[cityid+1]=1;
                    sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                            "%03d:%02d blue %s %d was killed in city %d\n",
                            time/60,time%60,names[blueproduce[attacker%5]],attacker+1,cityid+1);
                    redcenter.tmphp+=cities[cityid].hp;
                    sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                            "%03d:%02d red %s %d earned %d elements for his headquarter\n",
                            time/60,time%60,names[redproduce[defender%5]],defender+1,cities[cityid].hp);
                    cities[cityid].hp=0;
                    redwarriors[defender].win=1;
                    if(!strcmp(bluewarriors[attacker].name,"lion"))redwarriors[defender].hp+=tmp;
                    bluewarriors[attacker].state=0;
                    cities[cityid].bluehere=0;
                    cities[cityid].redwin++;
                    cities[cityid].bluewin=0;
                    if(cities[cityid].redwin==2 && cities[cityid].flag!=1)
                    {
                        cities[cityid].flag=1;
                        shouldoutput[cityid+1]=1;
                        sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                                "%03d:%02d red flag raised in city %d\n",
                                time/60,time%60,cityid+1);
                    }
                }
                else
                {
                    if(cities[cityid].bluehere && !strcmp(bluewarriors[cities[cityid].blueid].name,"dragon") && flag)
                    {
                        shouldoutput[cityid+1]=1;
                        sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                                "%03d:%02d blue dragon %d yelled in city %d\n",
                                time/60,time%60,cities[cityid].blueid+1,cityid+1);
                    }
                    cities[cityid].bluewin=cities[cityid].redwin=0;
                }
            }
            else
            {
                if(cities[cityid].bluehere && !strcmp(bluewarriors[cities[cityid].blueid].name,"dragon") && flag)
                {
                    shouldoutput[cityid+1]=1;
                    sprintf(outputstring[cityid+1]+strlen(outputstring[cityid+1]),
                            "%03d:%02d blue dragon %d yelled in city %d\n",
                            time/60,time%60,cities[cityid].blueid+1,cityid+1);
                }
                cities[cityid].bluewin=cities[cityid].redwin=0;
            }
        }
    }
}
void battle()
{
    int i;
    memset(shouldoutput,0,sizeof(shouldoutput));
    memset(outputstring,0,sizeof(outputstring));
    for(i=0; i<cityN; i++)
        if(cities[i].redhere && cities[i].bluehere)
        {
            if(cities[i].flag==1 || (cities[i].flag==0 && !(i&1)))//red attack first
                attack(i,cities[i].redid,cities[i].blueid,0);
            else attack(i,cities[i].blueid,cities[i].redid,1);
        }
    for(i=cityN-1; i>=0; i--)
        if(redwarriors[cities[i].redid].win)
        {
            redwarriors[cities[i].redid].win=0;
            if(redcenter.hp>=8)
            {
                redcenter.hp-=8;
                redwarriors[cities[i].redid].hp+=8;
            }
        }
    for(i=0; i<cityN; i++)
        if(bluewarriors[cities[i].blueid].win)
        {
            bluewarriors[cities[i].blueid].win=0;
            if(bluecenter.hp>=8)
            {
                bluecenter.hp-=8;
                bluewarriors[cities[i].blueid].hp+=8;
            }
        }
    redcenter.hp+=redcenter.tmphp;
    redcenter.tmphp=0;
    bluecenter.hp+=bluecenter.tmphp;
    bluecenter.tmphp=0;
}
void report()
{
    memset(shouldoutput,0,sizeof(shouldoutput));
    memset(outputstring,0,sizeof(outputstring));
    shouldoutput[0]=1;
    sprintf(outputstring[0],
            "%03d:%02d %d elements in red headquarter\n",
            time/60,time%60,redcenter.hp);
    shouldoutput[cityN+1]=1;
    sprintf(outputstring[cityN+1],
            "%03d:%02d %d elements in blue headquarter\n",
            time/60,time%60,bluecenter.hp);
}
void work()
{
    while(time<=maxtime && !gameover)
    {
        if(time%60==0)producewarriors();
        else if(time%60==10)warriorsmove();
        else if(time%60==20)producehp();
        else if(time%60==30)gethp();
        else if(time%60==40)battle();
        else report();//time%60==50
        output();
        time+=10;
    }
}
int main()
{
    //freopen("2.txt","r",stdin);
    //freopen("1.txt","w",stdout);
    int t,tt=0;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        init();
        printf("Case:%d\n",tt);
        work();
    }
    return 0;
}
