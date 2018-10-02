#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

bool val[7][7];

int main()
{
    char s[7][50]={"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"},tmp[100];
    int n,i,j,k,ii,jj,kk,sum,m,iii,jjj,kkk,iiii,jjjj;
    int a,b,c,aa,bb,cc,max,min,mmin=2147483647;
    scanf("%d",&n);
    memset(val,0,sizeof(val));
    while(n--)
    {
        memset(tmp,0,sizeof(tmp));
        scanf("%s",tmp);
        for(i=0;i<7;i++)
            if(strcmp(s[i],tmp)==0)break;
        memset(tmp,0,sizeof(tmp));
        scanf("%s",tmp);
        memset(tmp,0,sizeof(tmp));
        scanf("%s",tmp);
        for(j=0;j<7;j++)
            if(strcmp(s[j],tmp)==0)val[i][j]=1;
    }
    scanf("%d%d%d",&a,&b,&c);
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            for(k=1;k<=5;k++)
                if(i+j+k==7)
                {
                    aa=a;bb=b;cc=c;
                    a/=i;b/=j;c/=k;
                    if(a<b)
                    {
                        max=b;min=a;
                        if(b<c)max=c;
                        if(c<a)min=c;
                    }
                    else
                    {
                        max=a;min=b;
                        if(a<c)max=c;
                        if(c<b)min=c;
                    }     
                    if(max-min<mmin)
                    {
                        mmin=max-min;
                        ii=i;jj=j;kk=k;            
                    }
                    a=aa;b=bb;c=cc;
                }
    m=0;
    if(ii>jj)swap(ii,jj);
    if(ii>kk)swap(ii,kk);
    if(jj>kk)swap(jj,kk);
    cout<<ii<<' '<<jj<<' '<<kk<<endl;
    //*/
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)cout<<val[i][j]<<' ';
        cout<<endl;                
    }
    //*/
    if(ii==1 && jj==1 && kk==5)
    {
        for(i=0;i<7;i++)
            for(j=0;j<i;j++)
                if(i!=j)
                {
                    sum=0;
                    for(iii=0;iii<7;iii++)
                        for(jjj=0;jjj<7;jjj++)
                            if(iii!=i && iii!=j && jjj!=i && jjj!=j && val[iii][jjj])sum++;
                    if(sum>m)m=sum;        
                }         
    }
    else if(ii==1 && jj==2 && kk==4)
    {
        for(i=0;i<7;i++)
        {
            for(iii=0;iii<7;iii++)
                for(jjj=0;jjj<7;jjj++)
                if(iii!=jjj && iii!=i && jjj!=i)
                {
                    sum=val[iii][jjj]+val[jjj][iii]+val[iii][iii]+val[jjj][jjj];
                    for(iiii=0;iiii<7;iiii++)
                        for(jjjj=0;jjjj<7;jjjj++)
                            if(iiii!=i && jjjj!=i && iiii!=iii && jjjj!=jjj && iiii!=jjj && jjjj!=iii && val[iiii][jjjj])sum++;
                    if(sum>m)m=sum;                      
                }                
        }     
    }
    else if(ii==1 && jj==3 && kk==3)
    {
        for(iiii=0;iiii<7;iiii++)
        {
            for(i=0;i<7;i++)
                for(j=0;j<7;j++)
                    for(k=0;k<7;k++)
                        if(i!=j && i!=k && j!=k && iiii!=i && iiii!=j && iiii!=k)
                        {
                            sum=val[i][i]+val[i][j]+val[i][k]+val[j][i]+val[j][j]+val[j][k]+val[k][i]+val[k][j]+val[k][k];
                            bool flag[7];
                            memset(flag,0,sizeof(flag));
                            flag[iiii]=flag[i]=flag[j]=flag[k]=1;
                            for(iii=0;iii<7;iii++)if(flag[iii]==0){flag[iii]=1;break;}
                            for(jjj=0;jjj<7;jjj++)if(flag[jjj]==0){flag[jjj]=1;break;}
                            for(kkk=0;kkk<7;kkk++)if(flag[kkk]==0){flag[kkk]=1;break;}
                            sum+=(val[iii][iii]+val[iii][jjj]+val[iii][kkk]+val[jjj][iii]+val[jjj][jjj]+val[jjj][kkk]+val[kkk][iii]+val[kkk][jjj]+val[kkk][kkk]);
                            if(sum>m)m=sum;
                        }                         
        }     
    }
    else
    {
        for(iii=0;iii<7;iii++)
            for(jjj=0;jjj<7;jjj++)
                if(iii!=jjj)
                {
                    for(iiii=0;iiii<7;iiii++)
                        for(jjjj=0;jjjj<7;jjjj++)
                            if(iiii!=jjjj && iiii!=iii && iiii!=jjj && jjjj!=iii && jjjj!=jjj)
                            {
                                sum=val[iii][iii]+val[iii][jjj]+val[jjj][iii]+val[jjj][jjj];
                                sum+=val[iiii][iiii]+val[jjjj][jjjj]+val[iiii][jjjj]+val[jjjj][iiii];
                                bool flag[7];
                                memset(flag,0,sizeof(flag));
                                flag[iiii]=flag[jjjj]=flag[jjj]=flag[iii]=1;
                                for(i=0;i<7;i++)if(flag[i]==0){flag[i]=1;break;} 
                                for(j=0;j<7;j++)if(flag[j]==0){flag[j]=1;break;} 
                                for(k=0;k<7;k++)if(flag[k]==0){flag[k]=1;break;}
                                sum+=(val[i][i]+val[i][k]+val[i][j]+val[j][j]+val[j][i]+val[j][k]+val[k][j]+val[k][k]+val[k][i]);
                                if(sum>m){m=sum;}              
                            }            
                }    
    }
    printf("%d %d\n",mmin,m);
    
    system("pause");
    return 0;
}
