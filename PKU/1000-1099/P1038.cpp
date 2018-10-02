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
using namespace std;

int map[155][15];
int tri[12]= {0,1,3,9,27,81,243,729,2187,6561,19683,59049};
int dp[2][59049];// �ù��������¼ÿһ�е�״̬
int pre[15],now[15];//��һ���뱾�е�������״̬
int n,m;
int max(int a,int b)
{
    return (a>=b)?a:b;
}
int getten(int a[])// ��������״̬ת��Ϊʮ������
{
    int sum=0;
    for(int i=1; i<=m; ++i)
        sum+=tri[i]*a[i];
    return sum;
}
void gettri(int k,int a[])// ��ʮ������ת��������������
{
    for(int i=1; i<=m; ++i)
    {
        a[i]=k%3;
        k=k/3;
    }
    return;
}
void dfs(int i,int j,int last,int key)
//�ĸ�������i��ǰ�У�j��ǰ�У���ǰ״ֵ̬����ǰ״̬
{
    int k;
    dp[i%2][key]=max(dp[i%2][key],last);//�����Ķ������¸�״̬
    if(j>=m)
        return;
    if(!pre[j] && !pre[j+1] && !now[j] && !now[j+1])//�����и�
    {
        now[j]=now[j+1]=2;
        k=getten(now);
        dfs(i,j+2,last+1,k);
        now[j]=now[j+1]=0;
    }
    if(j<m-1 && !now[j] && !now[j+1] && !now[j+2])//�����и�
    {
        now[j]=now[j+1]=now[j+2]=2;
        k=getten(now);
        dfs(i,j+3,last+1,k);
        now[j]=now[j+1]=now[j+2]=0;
    }
    dfs(i,j+1,last,key);//�����Ķ���������һ��
    return;
}
int main ()
{
    int nn,k,a,b,tmp,ans;
    scanf("%d",&nn);
    while(nn--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<tri[m+1]; ++i)
            dp[1][i]=-1;// �ȳ�ʼ����1�е�ȫ��״̬���ǲ������γɵ�
        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j)
                map[j][i]=0;
        for(int i=1; i<=k; ++i)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        for(int i=1; i<=m; ++i)
            pre[i]=map[1][i]+1;//�����1�е�״̬��0�еķ���ȫ����Ϊ������
        tmp=getten(pre);
        dp[1][tmp]=0;//���õ�һ�е�ԭ��״̬�ǿ����γɵģ�״ֵ̬Ϊ0
        for(int i=2; i<=n; ++i)// ö����״̬
        {
            for(int j=0; j<tri[m+1]; ++j)// �����ø�״ֵ̬Ϊ-1���ȴ�����
                dp[i%2][j]=-1;
            for(int j=0; j<tri[m+1]; ++j)
            {
                if(dp[(i+1)%2][j]==-1)// ���������ܵ���״̬
                    continue;
                gettri(j,pre);
                for(int t=1; t<=m; ++t)
                {
                    if(map[i][t])
                        now[t]=2;
                    else
                        now[t]=max(pre[t]-1,0);
                }//������һ�е�״̬�õ����е�״̬
                tmp=getten(now);
                dfs(i,1,dp[(i+1)%2][j],tmp);
//������һ�����п��ܵ�״̬
            }
        }
        ans=0;
        for(int i=0; i<tri[m+1]; ++i)
            ans=max(ans,dp[n%2][i]);// �õ���
        printf("%d\n",ans);
    }
    return 0;
}
