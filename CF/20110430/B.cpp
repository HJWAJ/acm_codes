#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    __int64 n,m,k,t,ans,i,j,waste[10005],x,y;
    scanf("%I64d%I64d%I64d%I64d",&m,&n,&k,&t);
    for(i=0;i<k;i++)
    {
        scanf("%I64d%I64d",&x,&y);
        ans=(x-1)*n+y; 
        waste[i]=ans;
    }
    sort(waste,waste+k);
    //for(i=0;i<k;i++)cout<<waste[i]<<' ';
    //cout<<endl;
    for(i=0;i<t;i++)
    {
        scanf("%I64d%I64d",&x,&y);
        ans=(x-1)*n+y;
        //cout<<ans<<endl;
        j=0;
        while(waste[j]<ans && j<k)j++;
        if(waste[j]==ans)printf("Waste\n");
        else
        {
            ans-=j;
            if(ans%3==1)printf("Carrots\n");
            else if(ans%3==2)printf("Kiwis\n");
            else printf("Grapes\n");    
        }
    }
    
    //system("pause");    
    return 0;
}
