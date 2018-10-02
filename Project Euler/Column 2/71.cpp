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
struct divs
{
    long long p,q;
    bool operator <(const divs b) const
    {
        if(p*b.q - q*b.p<0)return 1;
        return 0;
    }
    bool operator >(const divs b) const
    {
        if(p*b.q - q*b.p>0)return 1;
        return 0;
    }
    bool operator >=(const divs b) const
    {
        if(p*b.q - q*b.p>=0)return 1;
        return 0;
    }
};
divs st;
int main()
{
    divs d,a,tmpd,tmpa;
    d.p=d.q=1;
    st.p=3;
    st.q=7;
    int p=1,q,ans,ans1;
    for(q=1;q<1000001;q++)
        while(1)
        {
            a.p=p;
            tmpa.p=p+1;
            tmpa.q=a.q=q;
            if(a>=st)break;
            else if(a<st && tmpa>=st)
            {
                tmpd.p=3*a.q-7*a.p;
                tmpd.q=7*a.q;
                if(tmpd<d)
                {
                    d=tmpd;
                    ans1=p;
                    ans=q;
                }
                break;
            }
            else p++;
        }
    printf("%d %d\n",ans1,ans);
    return 0;
}
