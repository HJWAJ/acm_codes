//����������������Ĳ���̫��ʵ����������194979����û������˼·ʱҪ�п��׵��ɵ��뷨�ͷ����������Ϻ�������ѵ�� 
/*
���⣺����ÿһλ��˵�����ֵ��9^5=59049��Ҳ����˵�������len��ʹlen*59049�п���>n������ȷ��һ��n�ķ�Χ�� 
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
using namespace std;
long long a[15],len;
long long getnum(long long n)
{
    int i=0;
    while(n)
    {
        a[i++]=n%10;
        n/=10;
    }
    return i;
}
long long pow(long long len)
{
    long long i,sum=0;
    for(i=0;i<len;i++)sum+=a[i]*a[i]*a[i]*a[i]*a[i];
    return sum;
}
int main()
{
    long long sum=0,tmp,i;
    for(i=2;i<10000000LL;i++)
    {
        len=getnum(i);
        if(pow(len)==i)
        {
            cout<<i<<endl;
            sum+=i;
        }
    }
    printf("%lld\n",sum);
    return 0;
}
