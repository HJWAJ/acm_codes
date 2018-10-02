/*
ID: hjw00002
PROG: lamps
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;

bool isSTD(int cnt[],int val[])
{
    int i;
    for(i=0;i<6;i++)
        if(val[i])
        {
            if((val[i]&1) && !(cnt[i]&1))return 0;
            if(!(val[i]&1) && (cnt[i]&1))return 0;
        }
    return 1;     
}

bool nAppear(char ans[][105],int cnt[],int flag)
{
    int i,j;
    for(i=0;i<flag;i++)
    {
        for(j=0;j<6;j++)
            if(ans[i][j]!=cnt[j]+'0')
                break;
        if(j==6)return 0;
    }
    return 1;
}

int cmp(const void *p,const void *q)
{
    char *a=(char *)p;
    char *b=(char *)q;
    return strcmp(a,b);    
}

int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    int n,c,on[105],off[105],f1,f2,i,ii[6],cnt[6],vall=0,sum=0,flag=0;
    char ans[105][105];
    scanf("%d%d",&n,&c);
    int val[105];
    memset(val,0,sizeof(val));
    f1=f2=0;
    while(scanf("%d",on+f1) && on[f1]!=-1)f1++;
    while(scanf("%d",off+f2) && off[f2]!=-1)f2++;
    for(i=0;i<f1;i++)val[(on[i]-1)%6]=1;
    for(i=0;i<f2;i++)
    {
        if(val[(off[i]-1)%6]==1){printf("IMPOSSIBLE\n");goto label;}
        else val[(off[i]-1)%6]=2;
    }
    for(ii[0]=0;ii[0]<2;ii[0]++)
        for(ii[1]=0;ii[1]<2;ii[1]++)
            for(ii[2]=0;ii[2]<2;ii[2]++)
                for(ii[3]=0;ii[3]<2;ii[3]++)
                {
                    sum=ii[0]+ii[1]+ii[2]+ii[3];
                    for(i=0;i<6;i++)cnt[i]=1;
                    if(sum<=c && !((c-sum)&1))
                    {
                        cnt[0]+=(ii[0]+ii[1]+ii[3]);
                        cnt[1]+=(ii[0]+ii[2]);
                        cnt[2]+=(ii[0]+ii[1]);
                        cnt[3]+=(ii[0]+ii[2]+ii[3]);
                        cnt[4]+=(ii[0]+ii[1]);
                        cnt[5]+=(ii[0]+ii[2]);
                        if(isSTD(cnt,val))
                        {
                            vall=1;
                            if(nAppear(ans,cnt,flag))
                            {
                                for(i=0;i<n;i++)ans[flag][i]=cnt[i%6]%2+'0';
                                flag++;
                            }
                        }          
                    }        
                }
    if(vall)
    {
        qsort(ans,flag,sizeof(ans[0]),cmp);
        for(i=0;i<flag;i++)printf("%s\n",ans[i]);       
    }
    else printf("IMPOSSIBLE\n");
    
    label:;
    //system("pause");
    return 0;
}
