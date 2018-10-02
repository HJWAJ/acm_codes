/*
ID: hjw00002
PROG: crypt1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    int n,i,a[10],loop[5],res1,res2,ans,cnt=0,val[10];
    memset(val,0,sizeof(val));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",a+i);
        val[a[i]]=1;
    }
    for(loop[0]=0;loop[0]<n;loop[0]++)
        for(loop[1]=0;loop[1]<n;loop[1]++)
            for(loop[2]=0;loop[2]<n;loop[2]++)
                for(loop[3]=0;loop[3]<n;loop[3]++)
                    for(loop[4]=0;loop[4]<n;loop[4]++)
                    {
                        res1=(a[loop[0]]*100+a[loop[1]]*10+a[loop[2]])*a[loop[4]];
                        res2=(a[loop[0]]*100+a[loop[1]]*10+a[loop[2]])*a[loop[3]];
                        ans=res1+res2*10;
                        i=3;
                        while(i--)
                        {
                            if(val[res1%10]==0)goto label;
                            res1/=10;           
                        }
                        if(res1!=0)goto label; 
                        i=3;           
                        while(i--)
                        {
                            if(val[res2%10]==0)goto label;
                            res2/=10;           
                        }
                        if(res2!=0)goto label;
                        i=4;
                        while(i--)
                        {
                            if(val[ans%10]==0)goto label;
                            ans/=10;           
                        }
                        if(ans!=0)goto label;
                        //cout<<a[loop[0]]<<' '<<a[loop[1]]<<' '<<a[loop[2]]<<' '<<a[loop[3]]<<' '<<a[loop[4]]<<endl;
                        cnt++;      
                        label:;
                    }
    printf("%d\n",cnt);
    
    //system("pause");
    return 0;
}
