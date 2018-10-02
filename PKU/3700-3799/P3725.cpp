#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
/**
 * 很显然,n>=m
 * 不管n取什么数，1都应该是第一位，同理10都应该在第二位，100都应该在第三位……10^(k-1)总应该在第k位
 * 所以如果m是10的整数次幂（包括0次幂）的情况下，如果k不等于lgm+1则输出0，否则就输出m
 * 单调性原理：如果n1<n2，则m在1~n1中的排序<=m在1-n2中的排序
 * 因为1～n2中比m字典序小的数包含了1~n1中比m字典序小的数
 * 所以如果1-m中m的字典序t比k要大，那么肯定是无解了。。。
 * 剩下的就肯定有解，因为如果x<y，且x,y是位数相同的数，则y字典序肯定比x大，所以肯定比m字典序大，这样就能的出一个结论
 * 在一个确定的位数中，可以得到确定的，字典序比n大的数的个数
 * 这个个数很好得到，比如比n的位数多1的话，（设n是i位数），那么比n字典序大的i+1位数的个数就是(n-10^(i-1))*10
 * 对于更高位，我们可以将n乘以10再计算，效果是一样的。。
 * 因为对于一个比n位数多的数，通过在n末尾补0，并不会改变n在这些高位数之间的字典序
 * 如果m=25，那么k最小为18，因此，如果k小于18则输出0。
 * 如果知道这个最小的k值，如果k值大于18，如题目的1000，那么我们就需要考虑了。
 * n为三位数，如100，每一个三位数的字典序小于25都可以使k值逼近1000，那么三位数是否足够呢？
 * 很显然，1 10 100 101 ......109 11......25，在每一个二位数之后都可以添加10个数，
 * 那么总共可以添加10*(25-10)=150个三位数，此时对于k为1000的数还是不够，
 * 那么考虑4位数，如1000，再看一下序列: 1 10 100 1000 1001 ......1009 101 ......25，观察可知，
 * 其实，每一个三位数又可以添加10个数，由于有150个三位数，于是可以有150*10=1500四位数在m值前面，比1000大，
 * 因此，锁定结果肯定是4位数，在25之前的一位数有2个，2位数有15个，3位数有150个，此时有2+15+150=167个，
 * 因此还需要（1000-1）-167=832个数在25之前，那么四位数中的第832个数即为所求，因此答案为1831。
 */
char m[15],k[15];
long long pow10(int n)
{
    long long res=1;
    int i;
    for(i=0;i<n;i++)res*=10;
    return res;
}
int main()
{
    long long ans,im,ik,x;
    int mlen,klen,i;
    while(scanf("%s%s",k,m)!=EOF)
    {
        im=ik=ans=x=0;
        mlen=strlen(m);
        klen=strlen(k);
        if(m[0]=='1')
        {
            for(i=1;i<mlen;i++)
                if(m[i]!='0')
                    break;
            if(i==mlen)
            {
                if(k[0]-'0'==mlen)printf("%lld\n",pow10(mlen-1));
                else puts("0");
                continue;
            }
        }
        for(i=0;i<mlen;i++)im=im*10+m[i]-'0';
        for(i=0;i<klen;i++)ik=ik*10+k[i]-'0';
        for(i=0;i<mlen;i++)
        {
            x=x*10+m[i]-'0';
            ans+=(x-pow10(i))+1;
        }
        if(ans>ik)
        {
            puts("0");
            continue;
        }
        else if(ans==ik)
        {
            printf("%lld\n",im);
            continue;
        }

        x=im-pow10(mlen-1);
        for(i=mlen;ans<=ik;i++)
        {
            x*=10;
            ans+=x;
        }
        ans-=x;
        x=ik-ans-1;
        printf("%lld\n",x+pow10(i-1));
    }
    return 0;
}
