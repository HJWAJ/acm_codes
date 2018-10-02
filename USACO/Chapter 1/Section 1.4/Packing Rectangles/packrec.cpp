/*
ID: hjw00002
PROG: packrec
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int w[4],h[4],minarea=999999,wm[100],hm[100],i,j,flag=0,ww,hh;

void check(int ww,int hh)
{
    if(ww*hh<minarea)
    {
        flag=0;
        minarea=ww*hh;
        wm[flag]=ww;
        hm[flag]=hh;
        return;              
    }     
    if(ww*hh==minarea)
    {
        flag++;
        wm[flag]=ww;
        hm[flag]=hh;
        return;                  
    }
    return;
}

void work(int w1,int w2,int w3,int w4,int h1,int h2,int h3,int h4)
{
    //1
    ww=w1+w2+w3+w4;
    hh=max(max(max(h1,h2),h3),h4);
    check(ww,hh);
    //2
    ww=max(w1+w2+w3,w4);
    hh=max(max(h1,h2),h3)+h4;
    check(ww,hh);
    //3
    ww=max(w1+w2,w3)+w4;
    hh=max(max(h1,h2)+h3,h4);
    check(ww,hh);
    //4,5
    ww=w1+w2+max(w3,w4);
    hh=max(max(h1,h2),h3+h4);
    check(ww,hh);
    //6
    hh=max(h1+h3,h2+h4);
    if(h3>=h2+h4)ww=max(w1,w3+max(w2,w4));
    if(h3>h4&&h3<h2+h4)ww=max(w1+w2,w3+max(w2,w4));
    if(h3<h4&&h4<h1+h3)ww=max(w1+w2,w4+max(w1,w3));
    if(h4>=h1+h3)ww=max(w2,w4+max(w1,w3));
    if(h3==h4)ww=max(w1+w2,w3+w4);
    check(ww,hh);
}

void solve()
{
    int s1,s2,s3,s4;
    for(s1=0;s1<4;s1++)
        for(s2=0;s2<4;s2++)
        if(s2!=s1)
            for(s3=0;s3<4;s3++)
            if(s3!=s1 && s3!=s2)
                for(s4=0;s4<4;s4++)
                if(s4!=s1 && s4!=s2 && s4!=s3)
                {
                    work(w[s1],w[s2],w[s3],w[s4],h[s1],h[s2],h[s3],h[s4]);
                    work(w[s1],w[s2],w[s3],h[s4],h[s1],h[s2],h[s3],w[s4]);
                    work(w[s1],w[s2],h[s3],w[s4],h[s1],h[s2],w[s3],h[s4]);
                    work(w[s1],h[s2],w[s3],w[s4],h[s1],w[s2],h[s3],h[s4]);
                    work(h[s1],w[s2],w[s3],w[s4],w[s1],h[s2],h[s3],h[s4]);
                    work(h[s1],h[s2],w[s3],w[s4],w[s1],w[s2],h[s3],h[s4]);
                    work(h[s1],w[s2],h[s3],w[s4],w[s1],h[s2],w[s3],h[s4]);
                    work(h[s1],w[s2],w[s3],h[s4],w[s1],h[s2],h[s3],w[s4]);
                    work(w[s1],h[s2],h[s3],w[s4],h[s1],w[s2],w[s3],h[s4]);
                    work(w[s1],h[s2],w[s3],h[s4],h[s1],w[s2],h[s3],w[s4]);
                    work(w[s1],w[s2],h[s3],h[s4],h[s1],h[s2],w[s3],w[s4]);
                    work(h[s1],h[s2],h[s3],w[s4],w[s1],w[s2],w[s3],h[s4]);
                    work(h[s1],h[s2],w[s3],h[s4],w[s1],w[s2],h[s3],w[s4]);
                    work(h[s1],w[s2],h[s3],h[s4],w[s1],h[s2],w[s3],w[s4]);
                    work(w[s1],h[s2],h[s3],h[s4],h[s1],w[s2],w[s3],w[s4]);
                    work(h[s1],h[s2],h[s3],h[s4],w[s1],w[s2],w[s3],w[s4]);          
                }
}

int main()
{
    freopen("packrec.in","r",stdin);
    freopen("packrec.out","w",stdout);
    
    for(i=0;i<4;i++)scanf("%d%d",w+i,h+i);
    solve();
    printf("%d\n",minarea);
    for(i=0;i<=flag;i++)if(wm[i]>hm[i])swap(wm[i],hm[i]);
    for(i=0;i<=flag;i++)
    {
        for(j=0;j<=flag-1-i;j++)
        {
            if(wm[j]>wm[j+1])
            {
                swap(wm[j],wm[j+1]);
                swap(hm[j],hm[j+1]);
            }                        
        }                    
    }
    for(i=0;i<=flag;i++)
    {
        for(j=0;j<i;j++)
        {
            if(wm[i]==wm[j] && hm[i]==hm[j])goto label;
        }
        printf("%d %d\n",wm[i],hm[i]);
        label:;
    }
    
    //system("pause");
    return 0;
}
