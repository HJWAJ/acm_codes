#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[30009],b[30009],ch;
int n; 

int test(int i,int j)
{
    int i1,j1;
    for(i1=i+1,j1=j-1;i1<j1;i1++,j1--)
    {
        if(a[i1]>a[j1])
        return j;
        if(a[i1]<a[j1])
        return i;
    }
    return i;
}
void cometonew()
{
     int i,j,kk=0;
     for(i=0,j=strlen(a)-1;i<=j; )
     {
        if(a[i]<a[j])
        {
           b[kk++]=a[i]; 
           i++;
        }
        else if(a[i]>a[j])
        {
           b[kk++]=a[j];
           j--;
        }
        else
        {   int pp=test(i,j);
            b[kk++]=a[pp];
            if(pp==i)
            i++;
            else
            j--;
        }
     }
     b[kk]='\0';
}
int main()
{   
    int i,j;
    cin>>n;
    getchar();
    for(i=0;i<n;i++)
    scanf("%c%c",&a[i],&ch);
    cometonew();
    j=strlen(b);
    for(i=0;i<j;i++)
    {
       printf("%c",b[i]);
       if((i+1)%80==0||i==j-1)
       printf("\n"); 
    }

    return 0;
}
