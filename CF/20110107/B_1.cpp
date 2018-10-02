#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    __int64 ssize1,ssize2,h,w,h1,w1,h2,w2;
    __int64 p2[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824}; 
    while(scanf("%I64d%I64d",&h,&w)!=EOF)
    {
        int i,val=0,val1=0;
        ssize1=ssize2=0;
        if(w>h){swap(w,h);val=1;}
        for(i=30;i>=0;i--)
        {
            if(p2[i]>w && p2[i]<=h && val1==0)
            {
                //h1=p2[i];
                if(p2[i]*0.8>w)continue;
                ssize1=p2[i]*w;
                h1=p2[i];w1=w;val1=1;continue;           
            }
            if(p2[i]<=w)
            {
                w2=p2[i];
                h2=(p2[i]*1.25>h?h:(int)(p2[i]*1.25));
                ssize2=h2*w2;
                break; 
            }                  
        }
        if(ssize1>=ssize2)
        {
            if(val==1)swap(h1,w1);
            printf("%I64d %I64d\n",h1,w1);               
        }
        else 
        {
            if(val==1)swap(h2,w2);
            printf("%I64d %I64d\n",h2,w2);     
        }
    }    
    
    return 0;
}
