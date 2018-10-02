#include<iostream>
using namespace std;
 
const int MAX = 10001;
int f[MAX];
long long int down[MAX],up[MAX],mini;

int main()
{
    int t,m,a,k,i,b;
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        memset(down,0,sizeof(down));
        memset(up,0,sizeof(up));
        cin>>m>>a>>b;
        for(i=1;i<=m;i++)
        {
            cin>>k;
            f[i]=k;
        }
        __int64 p=f[1],q=f[m], sum = 0;
        int besti = -1;
        down[1] = 0;
        for(i=2; i<=m; i++)
        {
            down[i] = down[i-1]+b*p+sum;
            sum+=p;
            p+=f[i];
        }
        sum = 0; up[m] = 0;
        for(i=m-1; i>=1; i--)
        {
            up[i] = up[i+1]+a*q+sum;
            sum += q;
            q += f[i];
        }
        mini=999999999999999;
        for(i=1; i<=m; i++)
        {
            if(mini>(down[i]+up[i]) )
            {
                mini = down[i]+up[i];
                besti = i;
            }
        }
        cout<<besti<<endl;
    }
    
    return 0;
}
