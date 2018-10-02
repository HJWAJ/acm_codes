#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int StrToNum(char s[])
{
    int digit=0;
    for(int i=0;s[i];i++)
        digit=digit*10+(s[i]-'0');
    return digit;
}
bool solve(int exp[])
{
    char s[30];
    cin>>s;
    if(s[0]=='E')    //END
        return false;
    else if(s[0]=='B')  //BEGIN
        while(solve(exp));   //����ΪOP���أ������������ΪEND���أ������
    else if(s[0]=='O')  //0P
    {
        cin>>s;
        exp[0]+=StrToNum(s);
        return solve(exp);
    }
    else     //LOOP
    {
        int TempExp[11]={0};  //��ʱexp[]
        cin>>s;
        while(solve(TempExp));
        if(s[0]=='n')   //LOOP n
        {
            for(int i=10;i>0;i--)TempExp[i]=TempExp[i-1];  //���ʽ����n����������Ĵ���+1
            TempExp[0]=0;
        }
        else  //LOOP Num
        {
            int x=StrToNum(s);
            for(int i=0;i<11;i++)TempExp[i]*=x; //���ʽ����const�����������ϵ��*const
        }
        for(int i=0;i<11;i++)exp[i]+=TempExp[i];
    }
    return true;
}
int main()
{
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        char s[6];
        int exp[11]={0};  //ָ��Ϊi�����ϵ��Ϊexp[i]
        solve(exp);
        cout<<"Program #"<<t<<endl;
        cout<<"Runtime = ";
        bool flag=false;
        bool before=false;  //��������ǰ��֮ǰ���Ƿ������ǰ�����
        for(int i=10;i>=0;i--)
            if(exp[i])   //��ϵ����Ϊ0ʱ�����������
            {
                flag=true;
                if(before)
                {
                    cout<<'+';
                    before=false;
                }

                if(!i)  //��ָ��Ϊ0ʱ��ֱ�����ϵ��
                {
                    cout<<exp[i];
                    before=false;
                }
                else
                {
                    bool sign=false;  //���ϵ���Ƿ�Ϊ1
                    if(i && exp[i]!=1)
                    {
                        sign=true;
                        cout<<exp[i];
                        before=true;
                    }
                    if(i)  //��ָ����Ϊ0ʱ
                    {
                        if(sign)cout<<'*';
                        cout<<'n';
                        if(i!=1)cout<<'^'<<i;
                        before=true;
                    }
                }
            }
        if(!flag)cout<<0<<endl<<endl;
        else cout<<endl<<endl;
    }
    return 0;
}
