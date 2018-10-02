#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int sol[9][9];
int cnt[9];

bool issol(int n)
{
    int i;
    if(cnt[n]!=1)return 0;
    for(i=0;i<9;i++)
    {
        if(i==n)continue;
        if(cnt[i]!=0)return 0;                
    }     
    return 1;
}

void solve()
{
    memset(sol,0,sizeof(sol));
    int a[9],i,j;
    for(a[0]=0;a[0]<4;a[0]++)
        for(a[1]=0;a[1]<4;a[1]++)
            for(a[2]=0;a[2]<4;a[2]++)
                for(a[3]=0;a[3]<4;a[3]++)
                    for(a[4]=0;a[4]<4;a[4]++)
                        for(a[5]=0;a[5]<4;a[5]++)
                            for(a[6]=0;a[6]<4;a[6]++)
                                for(a[7]=0;a[7]<4;a[7]++)
                                    for(a[8]=0;a[8]<4;a[8]++)
                                    {
                                        memset(cnt,0,sizeof(cnt));
                                        cnt[0]=(a[0]+a[1]+a[3])%4;
                                        cnt[1]=(a[0]+a[1]+a[2]+a[4])%4;
                                        cnt[2]=(a[1]+a[2]+a[5])%4;
                                        cnt[3]=(a[0]+a[3]+a[4]+a[6])%4;
                                        cnt[4]=(a[0]+a[2]+a[4]+a[6]+a[8])%4;
                                        cnt[5]=(a[2]+a[4]+a[5]+a[8])%4;
                                        cnt[6]=(a[3]+a[6]+a[7])%4;
                                        cnt[7]=(a[4]+a[6]+a[7]+a[8])%4;
                                        cnt[8]=(a[5]+a[7]+a[8])%4;
                                        for(i=0;i<9;i++)
                                        {
                                            if(issol(i))
                                            {
                                                /*
                                                for(j=0;j<9;j++)printf("%d ",cnt[j]);
                                                printf("\n");
                                                */
                                                for(j=0;j<9;j++)sol[i][j]=a[j];
                                                break;
                                            }
                                        }                        
                                    }//end for
    /*
    printf("\n");
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)printf("%d ",sol[i][j]);
        printf("\n");
    }
    printf("\n");
    */
}

int main()
{
    solve();
    int i,j,val[9],flag[9];
    memset(flag,0,sizeof(flag));
    for(i=0;i<9;i++)
    {
        scanf("%d",val+i);
        for(j=0;j<9;j++)
        {
            flag[j]+=(sol[i][j]*(4-val[i]));
            flag[j]%=4;                
        }
    }
    /*
    for(i=0;i<9;i++)printf("%d ",flag[i]);
    printf("\n");
    printf("\n");
    */
    for(i=0;i<9;i++)
        for(j=0;j<flag[i];j++)
        {
            printf("%d",i+1);
            goto label;
        }
    label:j++;
    for(;j<flag[i];j++)printf(" %d",i+1);
    i++;
    for(;i<9;i++)
        for(j=0;j<flag[i];j++)
            printf(" %d",i+1);
    printf("\n");
    
    //system("pause");
    return 0;
}
