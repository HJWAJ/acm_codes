#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
//调了半天居然是审题问题。。GG
char cmap[]="MDCLXVI";
char ans[25];
int nmap[]={1000,500,100,50,10,5,1};
int getdigit(char ch)
{
    for(int i=0;i<7;i++)
        if(cmap[i]==ch)
            return nmap[i];
    exit(-1);
}
bool smaller(char a,char b)
{
    int aa,bb,i;
    for(i=0;i<7;i++)
        if(cmap[i]==a)
        {
            aa=i;
            break;
        }
    for(i=0;i<7;i++)
        if(cmap[i]==b)
        {
            bb=i;
            break;
        }
    if(aa>bb)return 1;
    return 0;
}
int getnum(char s[],int len)
{
    int res=0,i;
    for(i=0;i<len-1;i++)
    {
        if(smaller(s[i],s[i+1]))res-=getdigit(s[i]);
        else res+=getdigit(s[i]);
    }
    res+=getdigit(s[i]);
    return res;
}
int getlen(int n)
{
    ans[0]='\0';
    int len=n/1000,i;
    for(i=0;i<len;i++)strcat(ans,"M");
    n%=1000;
    if(n>=500)
    {
        if(n>=900)
        {
            len+=2;
            n-=900;
            strcat(ans,"CM");
        }
        else
        {
            len+=1;
            n-=500;
            strcat(ans,"D");
        }
    }
    if(n>=100)
    {
        if(n>=400)
        {
            len+=2;
            n-=400;
            strcat(ans,"CD");
        }
        else
        {
            len+=n/100;
            for(i=0;i<n/100;i++)strcat(ans,"C");
            n%=100;
        }
    }
    if(n>=50)
    {
        if(n>=90)
        {
            len+=2;
            n-=90;
            strcat(ans,"XC");
        }
        else
        {
            len+=1;
            n-=50;
            strcat(ans,"L");
        }
    }
    if(n>=10)
    {
        if(n>=40)
        {
            len+=2;
            n-=40;
            strcat(ans,"XL");
        }
        else
        {
            len+=n/10;
            for(i=0;i<n/10;i++)strcat(ans,"X");
            n%=10;
        }
    }
    if(n>=5)
    {
        if(n==9)
        {
            len+=2;
            strcat(ans,"IX");
            return len;
        }
        else
        {
            len+=1;
            strcat(ans,"V");
            n-=5;
        }
    }
    if(n==4)
    {
        len+=2;
        strcat(ans,"IV");
    }
    else
    {
        for(i=0;i<n;i++)strcat(ans,"I");
        len+=n;
    }
    return len;
}
int main()
{
    freopen("roman.txt","r",stdin);
    freopen("romanout.txt","w",stdout);
    char s[25];
    int sum=0,tmp,len,t=0,sum0=0;
    while(scanf("%s",s)!=EOF)
    {
        t++;
        sum0+=strlen(s);
        tmp=getnum(s,strlen(s));
        cout<<tmp<<' ';
        len=getlen(tmp);
        cout<<len<<' '<<ans<<endl;
        if(tmp!=getnum(ans,strlen(ans)))exit(1);
        sum+=len;
    }
    printf("%d\n",sum0-sum);
    return 0;
}

/*

roman.txt:

MMMMDCLXXII
MMDCCCLXXXIII
MMMDLXVIIII
MMMMDXCV
DCCCLXXII
MMCCCVI
MMMCDLXXXVII
MMMMCCXXI
MMMCCXX
MMMMDCCCLXXIII
MMMCCXXXVII
MMCCCLXXXXIX
MDCCCXXIIII
MMCXCVI
CCXCVIII
MMMCCCXXXII
MDCCXXX
MMMDCCCL
MMMMCCLXXXVI
MMDCCCXCVI
MMMDCII
MMMCCXII
MMMMDCCCCI
MMDCCCXCII
MDCXX
CMLXXXVII
MMMXXI
MMMMCCCXIV
MLXXII
MCCLXXVIIII
MMMMCCXXXXI
MMDCCCLXXII
MMMMXXXI
MMMDCCLXXX
MMDCCCLXXIX
MMMMLXXXV
MCXXI
MDCCCXXXVII
MMCCCLXVII
MCDXXXV
CCXXXIII
CMXX
MMMCLXIV
MCCCLXXXVI
DCCCXCVIII
MMMDCCCCXXXIV
CDXVIIII
MMCCXXXV
MDCCCXXXII
MMMMD
MMDCCLXIX
MMMMCCCLXXXXVI
MMDCCXLII
MMMDCCCVIIII
DCCLXXXIIII
MDCCCCXXXII
MMCXXVII
DCCCXXX
CCLXIX
MMMXI
MMMMCMLXXXXVIII
MMMMDLXXXVII
MMMMDCCCLX
MMCCLIV
CMIX
MMDCCCLXXXIIII
CLXXXII
MMCCCCXXXXV
MMMMDLXXXVIIII
MMMDCCCXXI
MMDCCCCLXXVI
MCCCCLXX
MMCDLVIIII
MMMDCCCLIX
MMMMCCCCXIX
MMMDCCCLXXV
XXXI
CDLXXXIII
MMMCXV
MMDCCLXIII
MMDXXX
MMMMCCCLVII
MMMDCI
MMMMCDLXXXIIII
MMMMCCCXVI
CCCLXXXVIII
MMMMCML
MMMMXXIV
MMMCCCCXXX
DCCX
MMMCCLX
MMDXXXIII
CCCLXIII
MMDCCXIII
MMMCCCXLIV
CLXXXXI
CXVI
MMMMCXXXIII
CLXX
DCCCXVIII
MLXVII
DLXXXX
MMDXXI
MMMMDLXXXXVIII
MXXII
LXI
DCCCCXLIII
MMMMDV
MMMMXXXIV
MDCCCLVIII
MMMCCLXXII
MMMMDCCXXXVI
MMMMLXXXIX
MDCCCLXXXI
MMMMDCCCXV
MMMMCCCCXI
MMMMCCCLIII
MDCCCLXXI
MMCCCCXI
MLXV
MMCDLXII
MMMMDXXXXII
MMMMDCCCXL
MMMMCMLVI
CCLXXXIV
MMMDCCLXXXVI
MMCLII
MMMCCCCXV
MMLXXXIII
MMMV
MMMV
DCCLXII
MMDCCCCXVI
MMDCXLVIII
CCLIIII
CCCXXV
MMDCCLXXXVIIII
MMMMDCLXXVIII
MMMMDCCCXCI
MMMMCCCXX
MMCCXLV
MMMDCCCLXIX
MMCCLXIIII
MMMDCCCXLIX
MMMMCCCLXIX
CMLXXXXI
MCMLXXXIX
MMCDLXI
MMDCLXXVIII
MMMMDCCLXI
MCDXXV
DL
CCCLXXII
MXVIIII
MCCCCLXVIII
CIII
MMMDCCLXXIIII
MMMDVIII
MMMMCCCLXXXXVII
MMDXXVII
MMDCCLXXXXV
MMMMCXLVI
MMMDCCLXXXII
MMMDXXXVI
MCXXII
CLI
DCLXXXIX
MMMCLI
MDCLXIII
MMMMDCCXCVII
MMCCCLXXXV
MMMDCXXVIII
MMMCDLX
MMMCMLII
MMMIV
MMMMDCCCLVIII
MMMDLXXXVIII
MCXXIV
MMMMLXXVI
CLXXIX
MMMCCCCXXVIIII
DCCLXXXV
MMMDCCCVI
LI
CLXXXVI
MMMMCCCLXXVI
MCCCLXVI
CCXXXIX
MMDXXXXI
MMDCCCXLI
DCCCLXXXVIII
MMMMDCCCIV
MDCCCCXV
MMCMVI
MMMMCMLXXXXV
MMDCCLVI
MMMMCCXLVIII
DCCCCIIII
MMCCCCIII
MMMDCCLXXXVIIII
MDCCCLXXXXV
DVII
MMMV
DCXXV
MMDCCCXCV
DCVIII
MMCDLXVI
MCXXVIII
MDCCXCVIII
MMDCLX
MMMDCCLXIV
MMCDLXXVII
MMDLXXXIIII
MMMMCCCXXII
MMMDCCCXLIIII
DCCCCLXVII
MMMCLXXXXIII
MCCXV
MMMMDCXI
MMMMDCLXXXXV
MMMCCCLII
MMCMIX
MMDCCXXV
MMDLXXXVI
MMMMDCXXVIIII
DCCCCXXXVIIII
MMCCXXXIIII
MMDCCLXXVIII
MDCCLXVIIII
MMCCLXXXV
MMMMDCCCLXXXVIII
MMCMXCI
MDXLII
MMMMDCCXIV
MMMMLI
DXXXXIII
MMDCCXI
MMMMCCLXXXIII
MMMDCCCLXXIII
MDCLVII
MMCD
MCCCXXVII
MMMMDCCIIII
MMMDCCXLVI
MMMCLXXXVII
MMMCCVIIII
MCCCCLXXIX
DL
DCCCLXXVI
MMDXCI
MMMMDCCCCXXXVI
MMCII
MMMDCCCXXXXV
MMMCDXLV
MMDCXXXXIV
MMD
MDCCCLXXXX
MMDCXLIII
MMCCXXXII
MMDCXXXXVIIII
DCCCLXXI
MDXCVIIII
MMMMCCLXXVIII
MDCLVIIII
MMMCCCLXXXIX
MDCLXXXV
MDLVIII
MMMMCCVII
MMMMDCXIV
MMMCCCLXIIII
MMIIII
MMMMCCCLXXIII
CCIII
MMMCCLV
MMMDXIII
MMMCCCXC
MMMDCCCXXI
MMMMCCCCXXXII
CCCLVI
MMMCCCLXXXVI
MXVIIII
MMMCCCCXIIII
CLXVII
MMMCCLXX
CCCCLXIV
MMXXXXII
MMMMCCLXXXX
MXL
CCXVI
CCCCLVIIII
MMCCCII
MCCCLVIII
MMMMCCCX
MCDLXXXXIV
MDCCCXIII
MMDCCCXL
MMMMCCCXXIII
DXXXIV
CVI
MMMMDCLXXX
DCCCVII
MMCMLXIIII
MMMDCCCXXXIII
DCCC
MDIII
MMCCCLXVI
MMMCCCCLXXI
MMDCCCCXVIII
CCXXXVII
CCCXXV
MDCCCXII
MMMCMV
MMMMCMXV
MMMMDCXCI
DXXI
MMCCXLVIIII
MMMMCMLII
MDLXXX
MMDCLXVI
CXXI
MMMDCCCLIIII
MMMCXXI
MCCIII
MMDCXXXXI
CCXCII
MMMMDXXXV
MMMCCCLXV
MMMMDLXV
MMMCCCCXXXII
MMMCCCVIII
DCCCCLXXXXII
MMCLXIV
MMMMCXI
MLXXXXVII
MMMCDXXXVIII
MDXXII
MLV
MMMMDLXVI
MMMCXII
XXXIII
MMMMDCCCXXVI
MMMLXVIIII
MMMLX
MMMCDLXVII
MDCCCLVII
MMCXXXVII
MDCCCCXXX
MMDCCCLXIII
MMMMDCXLIX
MMMMCMXLVIII
DCCCLXXVIIII
MDCCCLIII
MMMCMLXI
MMMMCCLXI
MMDCCCLIII
MMMDCCCVI
MMDXXXXIX
MMCLXXXXV
MMDXXX
MMMXIII
DCLXXIX
DCCLXII
MMMMDCCLXVIII
MDCCXXXXIII
CCXXXII
MMMMDCXXV
MMMCCCXXVIII
MDCVIII
MMMCLXXXXIIII
CLXXXI
MDCCCCXXXIII
MMMMDCXXX
MMMDCXXIV
MMMCCXXXVII
MCCCXXXXIIII
CXVIII
MMDCCCCIV
MMMMCDLXXV
MMMDLXIV
MDXCIII
MCCLXXXI
MMMDCCCXXIV
MCXLIII
MMMDCCCI
MCCLXXX
CCXV
MMDCCLXXI
MMDLXXXIII
MMMMDCXVII
MMMCMLXV
MCLXVIII
MMMMCCLXXVI
MMMDCCLXVIIII
MMMMDCCCIX
DLXXXXIX
DCCCXXII
MMMMIII
MMMMCCCLXXVI
DCCCXCIII
DXXXI
MXXXIIII
CCXII
MMMDCCLXXXIIII
MMMCXX
MMMCMXXVII
DCCCXXXX
MMCDXXXVIIII
MMMMDCCXVIII
LV
MMMDCCCCVI
MCCCII
MMCMLXVIIII
MDCCXI
MMMMDLXVII
MMCCCCLXI
MMDCCV
MMMCCCXXXIIII
MMMMDI
MMMDCCCXCV
MMDCCLXXXXI
MMMDXXVI
MMMDCCCLVI
MMDCXXX
MCCCVII
MMMMCCCLXII
MMMMXXV
MMCMXXV
MMLVI
MMDXXX
MMMMCVII
MDC
MCCIII
MMMMDCC
MMCCLXXV
MMDCCCXXXXVI
MMMMCCCLXV
CDXIIII
MLXIIII
CCV
MMMCMXXXI
CCCCLXVI
MDXXXII
MMMMCCCLVIII
MMV
MMMCLII
MCMLI
MMDCCXX
MMMMCCCCXXXVI
MCCLXXXI
MMMCMVI
DCCXXX
MMMMCCCLXV
DCCCXI
MMMMDCCCXIV
CCCXXI
MMDLXXV
CCCCLXXXX
MCCCLXXXXII
MMDCIX
DCCXLIIII
DXIV
MMMMCLII
CDLXI
MMMCXXVII
MMMMDCCCCLXIII
MMMDCLIIII
MCCCCXXXXII
MMCCCLX
CCCCLIII
MDCCLXXVI
MCMXXIII
MMMMDLXXVIII
MMDCCCCLX
MMMCCCLXXXX
MMMCDXXVI
MMMDLVIII
CCCLXI
MMMMDCXXII
MMDCCCXXI
MMDCCXIII
MMMMCLXXXVI
MDCCCCXXVI
MDV
MMDCCCCLXXVI
MMMMCCXXXVII
MMMDCCLXXVIIII
MMMCCCCLXVII
DCCXLI
MMCLXXXVIII
MCCXXXVI
MMDCXLVIII
MMMMCXXXII
MMMMDCCLXVI
MMMMCMLI
MMMMCLXV
MMMMDCCCXCIV
MCCLXXVII
LXXVIIII
DCCLII
MMMCCCXCVI
MMMCLV
MMDCCCXXXXVIII
DCCCXV
MXC
MMDCCLXXXXVII
MMMMCML
MMDCCCLXXVIII
DXXI
MCCCXLI
DCLXXXXI
MMCCCLXXXXVIII
MDCCCCLXXVIII
MMMMDXXV
MMMDCXXXVI
MMMCMXCVII
MMXVIIII
MMMDCCLXXIV
MMMCXXV
DXXXVIII
MMMMCLXVI
MDXII
MMCCCLXX
CCLXXI
DXIV
MMMCLIII
DLII
MMMCCCXLIX
MMCCCCXXVI
MMDCXLIII
MXXXXII
CCCLXXXV
MDCLXXVI
MDCXII
MMMCCCLXXXIII
MMDCCCCLXXXII
MMMMCCCLXXXV
MMDCXXI
DCCCXXX
MMMDCCCCLII
MMMDCCXXII
MMMMCDXCVIII
MMMCCLXVIIII
MMXXV
MMMMCDXIX
MMMMCCCX
MMMCCCCLXVI
MMMMDCLXXVIIII
MMMMDCXXXXIV
MMMCMXII
MMMMXXXIII
MMMMDLXXXII
DCCCLIV
MDXVIIII
MMMCLXXXXV
CCCCXX
MMDIX
MMCMLXXXVIII
DCCXLIII
DCCLX
D
MCCCVII
MMMMCCCLXXXIII
MDCCCLXXIIII
MMMDCCCCLXXXVII
MMMMCCCVII
MMMDCCLXXXXVI
CDXXXIV
MCCLXVIII
MMMMDLX
MMMMDXII
MMMMCCCCLIIII
MCMLXXXXIII
MMMMDCCCIII
MMDCLXXXIII
MDCCCXXXXIV
XXXXVII
MMMDCCCXXXII
MMMDCCCXLII
MCXXXV
MDCXXVIIII
MMMCXXXXIIII
MMMMCDXVII
MMMDXXIII
MMMMCCCCLXI
DCLXXXXVIIII
LXXXXI
CXXXIII
MCDX
MCCLVII
MDCXXXXII
MMMCXXIV
MMMMLXXXX
MMDCCCCXLV
MLXXX
MMDCCCCLX
MCDLIII
MMMCCCLXVII
MMMMCCCLXXIV
MMMDCVIII
DCCCCXXIII
MMXCI
MMDCCIV
MMMMDCCCXXXIV
CCCLXXI
MCCLXXXII
MCMIII
CCXXXI
DCCXXXVIII
MMMMDCCXLVIIII
MMMMCMXXXV
DCCCLXXV
DCCXCI
MMMMDVII
MMMMDCCCLXVIIII
CCCXCV
MMMMDCCXX
MCCCCII
MMMCCCXC
MMMCCCII
MMDCCLXXVII
MMDCLIIII
CCXLIII
MMMDCXVIII
MMMCCCIX
MCXV
MMCCXXV
MLXXIIII
MDCCXXVI
MMMCCCXX
MMDLXX
MMCCCCVI
MMDCCXX
MMMMDCCCCXCV
MDCCCXXXII
MMMMDCCCCXXXX
XCIV
MMCCCCLX
MMXVII
MLXXI
MMMDXXVIII
MDCCCCII
MMMCMLVII
MMCLXXXXVIII
MDCCCCLV
MCCCCLXXIIII
MCCCLII
MCDXLVI
MMMMDXVIII
DCCLXXXIX
MMMDCCLXIV
MDCCCCXLIII
CLXXXXV
MMMMCCXXXVI
MMMDCCCXXI
MMMMCDLXXVII
MCDLIII
MMCCXLVI
DCCCLV
MCDLXX
DCLXXVIII
MMDCXXXIX
MMMMDCLX
MMDCCLI
MMCXXXV
MMMCCXII
MMMMCMLXII
MMMMCCV
MCCCCLXIX
MMMMCCIII
CLXVII
MCCCLXXXXIIII
MMMMDCVIII
MMDCCCLXI
MMLXXIX
CMLXIX
MMDCCCXLVIIII
DCLXII
MMMCCCXLVII
MDCCCXXXV
MMMMDCCXCVI
DCXXX
XXVI
MMLXIX
MMCXI
DCXXXVII
MMMMCCCXXXXVIII
MMMMDCLXI
MMMMDCLXXIIII
MMMMVIII
MMMMDCCCLXII
MDCXCI
MMCCCXXIIII
CCCCXXXXV
MMDCCCXXI
MCVI
MMDCCLXVIII
MMMMCXL
MLXVIII
CMXXVII
CCCLV
MDCCLXXXIX
MMMCCCCLXV
MMDCCLXII
MDLXVI
MMMCCCXVIII
MMMMCCLXXXI
MMCXXVII
MMDCCCLXVIII
MMMCXCII
MMMMDCLVIII
MMMMDCCCXXXXII
MMDCCCCLXXXXVI
MDCCXL
MDCCLVII
MMMMDCCCLXXXVI
DCCXXXIII
MMMMDCCCCLXXXV
MMCCXXXXVIII
MMMCCLXXVIII
MMMDCLXXVIII
DCCCI
MMMMLXXXXVIIII
MMMCCCCLXXII
MMCLXXXVII
CCLXVI
MCDXLIII
MMCXXVIII
MDXIV
CCCXCVIII
CLXXVIII
MMCXXXXVIIII
MMMDCLXXXIV
CMLVIII
MCDLIX
MMMMDCCCXXXII
MMMMDCXXXIIII
MDCXXI
MMMDCXLV
MCLXXVIII
MCDXXII
IV
MCDLXXXXIII
MMMMDCCLXV
CCLI
MMMMDCCCXXXVIII
DCLXII
MCCCLXVII
MMMMDCCCXXXVI
MMDCCXLI
MLXI
MMMCDLXVIII
MCCCCXCIII
XXXIII
MMMDCLXIII
MMMMDCL
DCCCXXXXIIII
MMDLVII
DXXXVII
MCCCCXXIIII
MCVII
MMMMDCCXL
MMMMCXXXXIIII
MCCCCXXIV
MMCLXVIII
MMXCIII
MDCCLXXX
MCCCLIIII
MMDCLXXI
MXI
MCMLIV
MMMCCIIII
DCCLXXXVIIII
MDCLIV
MMMDCXIX
CMLXXXI
DCCLXXXVII
XXV
MMMXXXVI
MDVIIII
CLXIII
MMMCDLVIIII
MMCCCCVII
MMMLXX
MXXXXII
MMMMCCCLXVIII
MMDCCCXXVIII
MMMMDCXXXXI
MMMMDCCCXXXXV
MMMXV
MMMMCCXVIIII
MMDCCXIIII
MMMXXVII
MDCCLVIIII
MMCXXIIII
MCCCLXXIV
DCLVIII
MMMLVII
MMMCXLV
MMXCVII
MMMCCCLXXXVII
MMMMCCXXII
DXII
MMMDLV
MCCCLXXVIII
MMMCLIIII
MMMMCLXXXX
MMMCLXXXIIII
MDCXXIII
MMMMCCXVI
MMMMDLXXXIII
MMMDXXXXIII
MMMMCCCCLV
MMMDLXXXI
MMMCCLXXVI
MMMMXX
MMMMDLVI
MCCCCLXXX
MMMXXII
MMXXII
MMDCCCCXXXI
MMMDXXV
MMMDCLXXXVIIII
MMMDLXXXXVII
MDLXIIII
CMXC
MMMXXXVIII
MDLXXXVIII
MCCCLXXVI
MMCDLIX
MMDCCCXVIII
MDCCCXXXXVI
MMMMCMIV
MMMMDCIIII
MMCCXXXV
XXXXVI
MMMMCCXVII
MMCCXXIV
MCMLVIIII
MLXXXIX
MMMMLXXXIX
CLXXXXIX
MMMDCCCCLVIII
MMMMCCLXXIII
MCCCC
DCCCLIX
MMMCCCLXXXII
MMMCCLXVIIII
MCLXXXV
CDLXXXVII
DCVI
MMX
MMCCXIII
MMMMDCXX
MMMMXXVIII
DCCCLXII
MMMMCCCXLIII
MMMMCLXV
DXCI
MMMMCLXXX
MMMDCCXXXXI
MMMMXXXXVI
DCLX
MMMCCCXI
MCCLXXX
MMCDLXXII
DCCLXXI
MMMCCCXXXVI
MCCCCLXXXVIIII
CDLVIII
DCCLVI
MMMMDCXXXVIII
MMCCCLXXXIII
MMMMDCCLXXV
MMMXXXVI
CCCLXXXXIX
CV
CCCCXIII
CCCCXVI
MDCCCLXXXIIII
MMDCCLXXXII
MMMMCCCCLXXXI
MXXV
MMCCCLXXVIIII
MMMCCXII
MMMMCCXXXIII
MMCCCLXXXVI
MMMDCCCLVIIII
MCCXXXVII
MDCLXXV
XXXV
MMDLI
MMMCCXXX
MMMMCXXXXV
CCCCLIX
MMMMDCCCLXXIII
MMCCCXVII
DCCCXVI
MMMCCCXXXXV
MDCCCCXCV
CLXXXI
MMMMDCCLXX
MMMDCCCIII
MMCLXXVII
MMMDCCXXIX
MMDCCCXCIIII
MMMCDXXIIII
MMMMXXVIII
MMMMDCCCCLXVIII
MDCCCXX
MMMMCDXXI
MMMMDLXXXIX
CCXVI
MDVIII
MMCCLXXI
MMMDCCCLXXI
MMMCCCLXXVI
MMCCLXI
MMMMDCCCXXXIV
DLXXXVI
MMMMDXXXII
MMMXXIIII
MMMMCDIV
MMMMCCCXLVIII
MMMMCXXXVIII
MMMCCCLXVI
MDCCXVIII
MMCXX
CCCLIX
MMMMDCCLXXII
MDCCCLXXV
MMMMDCCCXXIV
DCCCXXXXVIII
MMMDCCCCXXXVIIII
MMMMCCXXXV
MDCLXXXIII
MMCCLXXXIV
MCLXXXXIIII
DXXXXIII
MCCCXXXXVIII
MMCLXXIX
MMMMCCLXIV
MXXII
MMMCXIX
MDCXXXVII
MMDCCVI
MCLXXXXVIII
MMMCXVI
MCCCLX
MMMCDX
CCLXVIIII
MMMCCLX
MCXXVIII
LXXXII
MCCCCLXXXI
MMMI
MMMCCCLXIV
MMMCCCXXVIIII
CXXXVIII
MMCCCXX
MMMCCXXVIIII
MCCLXVI
MMMCCCCXXXXVI
MMDCCXCIX
MCMLXXI
MMCCLXVIII
CDLXXXXIII
MMMMDCCXXII
MMMMDCCLXXXVII
MMMDCCLIV
MMCCLXIII
MDXXXVII
DCCXXXIIII
MCII
MMMDCCCLXXI
MMMLXXIII
MDCCCLIII
MMXXXVIII
MDCCXVIIII
MDCCCCXXXVII
MMCCCXVI
MCMXXII
MMMCCCLVIII
MMMMDCCCXX
MCXXIII
MMMDLXI
MMMMDXXII
MDCCCX
MMDXCVIIII
MMMDCCCCVIII
MMMMDCCCCXXXXVI
MMDCCCXXXV
MMCXCIV
MCMLXXXXIII
MMMCCCLXXVI
MMMMDCLXXXV
CMLXIX
DCXCII
MMXXVIII
MMMMCCCXXX
XXXXVIIII

*/
