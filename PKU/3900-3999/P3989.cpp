#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s1[10],s2[10],s3[10],ss1[10],ss2[10],ss3[10];
int str2int(char s[])
{
    int i,len=strlen(s),num=0;
    for(i=0;i<len;i++)
    {
        num*=10;
        num+=s[i]-'0';
    }
    return num;
}
bool ish(int n)
{
    if((s1[0]==char(n+'A')&&strlen(s1)>1) || (s2[0]==char(n+'A')&&strlen(s2)>1) || (s3[0]==char(n+'A')&&strlen(s3)>1))return true;
    return false;
}
int main()
{
    int t,len1,len2,len3,cnt,i,j,a[5],num,n1,n2,n3,flag[5],tmp;
    bool bo[10],bo1[5];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%s",s1,s2,s3);
        len1=strlen(s1);
        len2=strlen(s2);
        len3=strlen(s3);
        memset(bo1,0,sizeof(bo1));
        cnt=0;
        for(i=0;i<len1;i++)bo1[s1[i]-'A']=1;
        for(i=0;i<len2;i++)bo1[s2[i]-'A']=1;
        for(i=0;i<len3;i++)bo1[s3[i]-'A']=1;
        j=0;
        for(i=0;i<5;i++)if(bo1[i])flag[j++]=i;
        cnt=j;
        for(i=0;i<len1;i++)
        {
            tmp=s1[i]-'A';
            for(j=0;j<cnt;j++)
                if(flag[j]==tmp)s1[i]='A'+j;
        }
        for(i=0;i<len2;i++)
        {
            tmp=s2[i]-'A';
            for(j=0;j<cnt;j++)
                if(flag[j]==tmp)s2[i]='A'+j;
        }
        for(i=0;i<len3;i++)
        {
            tmp=s3[i]-'A';
            for(j=0;j<cnt;j++)
                if(flag[j]==tmp)s3[i]='A'+j;
        }
        strcpy(ss1,s1);
        strcpy(ss2,s2);
        strcpy(ss3,s3);
        for(i=0;i<len1;i++)
        num=0;
        memset(bo,0,sizeof(bo));
        for(a[0]=0;a[0]<10;a[0]++)
        {
            if(ish(0) && a[0]==0)continue;
            bo[a[0]]=1;
            if(cnt>1)
            {
                for(a[1]=0;a[1]<10;a[1]++)
                if(!bo[a[1]])
                {
                    if(ish(1) && a[1]==0)continue;
                    bo[a[1]]=1;
                    if(cnt>2)
                    {
                        for(a[2]=0;a[2]<10;a[2]++)
                        if(!bo[a[2]])
                        {
                            if(ish(2) && a[2]==0)continue;
                            bo[a[2]]=1;
                            if(cnt>3)
                            {
                                for(a[3]=0;a[3]<10;a[3]++)
                                if(!bo[a[3]])
                                {
                                    if(ish(3) && a[3]==0)continue;
                                    bo[a[3]]=1;
                                    if(cnt>4)
                                    {
                                        for(a[4]=0;a[4]<10;a[4]++)
                                        if(!bo[a[4]])
                                        {
                                            if(ish(4) && a[4]==0)continue;
                                            //cout<<"********"<<endl;
                                            for(i=0;i<len1;i++)s1[i]=a[s1[i]-'A']+'0';
                                            for(i=0;i<len2;i++)s2[i]=a[s2[i]-'A']+'0';
                                            for(i=0;i<len3;i++)s3[i]=a[s3[i]-'A']+'0';
                                            n1=str2int(s1);
                                            n2=str2int(s2);
                                            n3=str2int(s3);
                                            //cout<<"********"<<endl;
                                            //for(i=0;i<5;i++)cout<<a[i]<<' ';
                                            //cout<<endl;
                                            //cout<<n1<<' '<<n2<<' '<<n3<<endl;
                                            if(n1+n2==n3)num++;
                                            if(n1-n2==n3)num++;
                                            if(n1*n2==n3)num++;
                                            if(n2 && n1/n2==n3 && n1%n2==0)num++;
                                            strcpy(s1,ss1);
                                            strcpy(s2,ss2);
                                            strcpy(s3,ss3);
                                        }
                                    }
                                    else
                                    {
                                        for(i=0;i<len1;i++)s1[i]=a[s1[i]-'A']+'0';
                                        for(i=0;i<len2;i++)s2[i]=a[s2[i]-'A']+'0';
                                        for(i=0;i<len3;i++)s3[i]=a[s3[i]-'A']+'0';
                                        n1=str2int(s1);
                                        n2=str2int(s2);
                                        n3=str2int(s3);
                                        //cout<<"********"<<endl;
                                        //for(i=0;i<5;i++)cout<<a[i]<<' ';
                                        //cout<<endl;
                                        //cout<<n1<<' '<<n2<<' '<<n3<<endl;
                                        if(n1+n2==n3)num++;
                                        if(n1-n2==n3)num++;
                                        if(n1*n2==n3)num++;
                                        if(n2 && n1/n2==n3 && n1%n2==0)num++;
                                        strcpy(s1,ss1);
                                        strcpy(s2,ss2);
                                        strcpy(s3,ss3);
                                    }
                                    bo[a[3]]=0;
                                }
                            }
                            else
                            {
                                for(i=0;i<len1;i++)s1[i]=a[s1[i]-'A']+'0';
                                for(i=0;i<len2;i++)s2[i]=a[s2[i]-'A']+'0';
                                for(i=0;i<len3;i++)s3[i]=a[s3[i]-'A']+'0';
                                n1=str2int(s1);
                                n2=str2int(s2);
                                n3=str2int(s3);
                                //cout<<"********"<<endl;
                                //for(i=0;i<5;i++)cout<<a[i]<<' ';
                                //cout<<endl;
                                //cout<<n1<<' '<<n2<<' '<<n3<<endl;
                                if(n1+n2==n3)num++;
                                if(n1-n2==n3)num++;
                                if(n1*n2==n3)num++;
                                if(n2 && n1/n2==n3 && n1%n2==0)num++;
                                strcpy(s1,ss1);
                                strcpy(s2,ss2);
                                strcpy(s3,ss3);
                            }
                            bo[a[2]]=0;
                        }
                    }
                    else
                    {
                        for(i=0;i<len1;i++)s1[i]=a[s1[i]-'A']+'0';
                        for(i=0;i<len2;i++)s2[i]=a[s2[i]-'A']+'0';
                        for(i=0;i<len3;i++)s3[i]=a[s3[i]-'A']+'0';
                        n1=str2int(s1);
                        n2=str2int(s2);
                        n3=str2int(s3);
                        //cout<<"********"<<endl;
                        //for(i=0;i<5;i++)cout<<a[i]<<' ';
                        //cout<<endl;
                        //cout<<n1<<' '<<n2<<' '<<n3<<endl;
                        if(n1+n2==n3)num++;
                        if(n1-n2==n3)num++;
                        if(n1*n2==n3)num++;
                        if(n2 && n1/n2==n3 && n1%n2==0)num++;
                        strcpy(s1,ss1);
                        strcpy(s2,ss2);
                        strcpy(s3,ss3);
                    }
                    bo[a[1]]=0;
                }
            }
            else
            {
                for(i=0;i<len1;i++)s1[i]=a[s1[i]-'A']+'0';
                for(i=0;i<len2;i++)s2[i]=a[s2[i]-'A']+'0';
                for(i=0;i<len3;i++)s3[i]=a[s3[i]-'A']+'0';
                //cout<<s1<<' '<<s2<<' '<<s3<<' ';
                n1=str2int(s1);
                n2=str2int(s2);
                n3=str2int(s3);
                //cout<<"********"<<endl;
                //for(i=0;i<5;i++)cout<<a[i]<<' ';
                //cout<<endl;
                //cout<<n1<<' '<<n2<<' '<<n3<<endl;
                if(n1+n2==n3)num++;
                if(n1-n2==n3)num++;
                if(n1*n2==n3)num++;
                if(n2 && n1/n2==n3 && n1%n2==0)num++;
                strcpy(s1,ss1);
                strcpy(s2,ss2);
                strcpy(s3,ss3);
            }
            bo[a[0]]=0;
        }
        printf("%d\n",num);
    }
    //system("pause");
    return 0;
}
