#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct node
{
    char s[5];
    int a,b;       
}nod[100];

bool check(int i,int j,int k,int l,char s[],int m,int n)
{
    int cnt1,cnt2;
    cnt1=cnt2=0;
    if(i==s[0]-'0')cnt1++;
    if(j==s[1]-'0')cnt1++;
    if(k==s[2]-'0')cnt1++;
    if(l==s[3]-'0')cnt1++;
    
    if(j==s[0]-'0')cnt2++;
    if(k==s[0]-'0')cnt2++;
    if(l==s[0]-'0')cnt2++;
    if(i==s[1]-'0')cnt2++;
    if(k==s[1]-'0')cnt2++;
    if(l==s[1]-'0')cnt2++;
    if(i==s[2]-'0')cnt2++;
    if(j==s[2]-'0')cnt2++;
    if(l==s[2]-'0')cnt2++;
    if(i==s[3]-'0')cnt2++;
    if(j==s[3]-'0')cnt2++;
    if(k==s[3]-'0')cnt2++;
    if(m==cnt1 && n==cnt2)return 1;
    return 0;
}

int main()
{
    int i,j,k,l,ii,n,cnt=0,ans[4];
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s%d%d",nod[i].s,&nod[i].a,&nod[i].b);
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(j!=i)
                for(k=0;k<10;k++)
                    if(k!=j && k!=i)
                        for(l=0;l<10;l++)
                            if(l!=k && l!=j && l!=i)
                            {
                                for(ii=0;ii<n;ii++)
                                    if(!check(i,j,k,l,nod[ii].s,nod[ii].a,nod[ii].b))break;
                                if(ii==n)
                                {
                                    ans[0]=i;
                                    ans[1]=j;
                                    ans[2]=k;
                                    ans[3]=l;
                                    cnt++;
                                    if(cnt==2){printf("Need more data\n");goto label;}
                                }                                                
                            }
    if(cnt==0)printf("Incorrect data\n");
    else if(cnt==1)
    {
        for(i=0;i<4;i++)printf("%d",ans[i]);
        printf("\n");
    }
    label:;
    //system("pause");
    return 0;
}
