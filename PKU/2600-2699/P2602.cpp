#include<iostream>
using namespace std;

char a[1000000],b[1000000],c[1000001];

int main()
{
    int n,i;
    bool val=0; 
    scanf("%d",&n);
    memset(c,0,sizeof(c));
    for(i=0;i<n;i++)
    {
        scanf("%s%s",&a[i],&b[i]);                
    }    
    for(i=n-1;i>=0;i--)
    {
        c[i]=c[i]+a[i]-'0'+b[i];
        if(c[i]>=10+'0' && i!=0){c[i-1]++;c[i]-=10;}
        else if(c[i]>=10+'0' && i==0){c[i]-=10;val=1;}                
    }
    c[n]='\0';
    if(val==1)printf("1");
    printf("%s\n",c);
    
    system("pause");
    return 0;
}
