#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
set<string> myset,sset;
string stk[200005];
int top;
int main()
{
    int n;
    string str,tmp;
    top=0;
    myset.clear();
    sset.clear();
    cin>>n;
    while(cin>>str)
    {
        if(str=="int")
        {
            myset.insert(str);
            stk[top++]=str;
            while(top>=3 && stk[top-3]=="pair" && (stk[top-2]=="int" || stk[top-2][stk[top-2].length()-1]=='>'))
            {
                stk[top-3]+="<";
                stk[top-3]+=stk[top-2];
                stk[top-3]+=",";
                stk[top-3]+=stk[top-1];
                stk[top-3]+=">";
                myset.insert(stk[top-3]);
                top-=2;
                if(top==1)
                {
                    sset.insert(stk[top-1]);
                    top--;
                }
            }
        }
        else
        {
            stk[top++]=str;
        }
    }
    //cout<<myset.size()<<' '<<sset.size()<<' '<<top<<endl;
    if(myset.size()==n && sset.size()==1 && top==0)cout<<stk[0]<<endl;
    else cout<<"Error occurred"<<endl;
	return 0;
}
