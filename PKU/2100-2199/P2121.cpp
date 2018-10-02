#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
char word[28][10]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
int num[28]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90};
char s[15];
int main()
{
    char ch;
    int sum=0,i,sum1=0,sum2=0;
    while(scanf("%s",s)!=EOF)
    {
        if(!strcmp(s,"negative"))printf("-");
        else if(!strcmp(s,"million"))
        {
            sum1=sum;
            sum=0;
        }
        else if(!strcmp(s,"thousand"))
        {
            sum2=sum;
            sum=0;
        }
        else if(!strcmp(s,"hundred"))sum*=100;
        else
        {
            for(i=0;i<28;i++)
                if(!strcmp(s,word[i]))
                {
                    sum+=num[i];
                    break;
                }
        }
        ch=getchar();
        if(ch=='\n')
        {
            printf("%d\n",sum+sum1*1000000+sum2*1000);
            sum=sum1=sum2=0;
        }
    }
    return 0;
}
