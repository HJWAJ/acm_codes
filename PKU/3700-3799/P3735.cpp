#include<iostream>
using namespace std;
typedef long long ll;
ll N,M,K;
class Matrix
{
      public:
      ll a[110][110];
      Matrix()
      {
           memset(a,0,sizeof(a));
      }
      void clear()
      {
           memset(a,0,sizeof(a));
      }
      void load()
      {
           int i;
           for(i=0;i<=N;++i)
              a[i][i] = 1;
      }
      void print()
      {
           int i,j;
           for(i=0;i<=N;++i)
           {
               for(j=0;j<=N;++j)
                  printf("%d ",a[i][j]);
               printf("\n");
           }
      }
      Matrix operator*(Matrix b)
      {
           Matrix c;
           c.clear();
           int i,j,k;
           for(i=0;i<=N;++i)
              for(k=0;k<=N;++k)
                 if(a[i][k]!=0)
                    for(j=0;j<=N;++j)
                       c.a[i][j] += a[i][k]*b.a[k][j];
           return c;
      }
};

Matrix muti(Matrix a,int t)
{
       Matrix c;
       c.clear();
       c.load();
       while(t>0)
       {
           if(t&1)
              c = c*a;
           a = a*a;
           t>>=1;
       }
       return c;
}

int main()
{
    char c[2];
    Matrix m;
    while(scanf("%lld%lld%lld",&N,&M,&K)==3)
    {
        if(N==0&M==0&K==0)
           break;
        m.clear();
        m.load();
        ll i,j,s,e;
        for(i=0;i<K;++i)
        {
            scanf("%s",c);
            if(c[0]=='g')
            {
                 scanf("%lld",&s);
                 m.a[s][0]++;
            }
            else if(c[0]=='s')
            {
                 scanf("%lld%lld",&s,&e);
                 for(j=0;j<=N;++j)
                    swap(m.a[s][j],m.a[e][j]);
            }
            else
            {
                scanf("%lld",&s);
                for(j=0;j<=N;++j)
                   m.a[s][j] = 0;
            }
        }
        m = muti(m,M);
        for(i=1;i<=N;++i)
           printf("%lld ",m.a[i][0]);
        printf("\n");
    }
    return 0;
}