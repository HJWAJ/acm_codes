#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,len,j,k,num[10000];
    __int64 leng=1;
    char s[10000],s1[10000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        leng=1;
        cin>>s;
        len=strlen(s);
        for(j=0;j<len;j++)
        {
            if(s[j]<'a')num[j]=(s[j]-'A'+1)*2-1;
            else num[j]=(s[j]-'a'+1)*2;                
        }
        sort(num,num+len);
        for(k=0;k<len;k++)
        {    
            if(num[k]%2==1)s[k]=char((num[k]+1)/2+'A'-1);
            else s[k]=char(num[k]/2+'a'-1);
        }
        cout<<s<<endl;
        strcpy(s1,s);
        for(j=len;j>0;j--)
            leng=leng*j;
        for(j=0;j<leng-1;j++)
        {
            next_permutation(num,num+len);
            for(k=0;k<len;k++)
            {    
                 if(num[k]%2==1)s[k]=char((num[k]+1)/2+'A'-1);
                 else s[k]=char(num[k]/2+'a'-1);
            }
            if(strcmp(s,s1)==0)break;
            cout<<s<<endl;
        }                        
    }
    
    system("pause");
    return 0;
}
