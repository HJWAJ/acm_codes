#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class Time
{
public:
    string whatTime(int seconds)
    {
        int h = seconds / 3600;
        int min = seconds % 3600 / 60;
        int s = seconds % 60;
        char str[50];
        memset(str, 0,sizeof(str));
        sprintf(str, "%d:%d:%d", h, min, s);
        string res = str;
        return res;
    }
};

class BinaryCode
{
public:
    vector<string> decode(string message)
    {
        string s1 = "0";
        int i;
        s1+=message[0];
        for(i=1;i<message.length()-1;i++)
        {
            s1+=char(message[i]-s1[i]-s1[i-1]+'0'+'0');
        }
        cout<<s1<<endl;
        string s2 = "1";
        s2+=(char)(message[0]-1);
        for(i=1;i<message.length()-1;i++)
        {
            s2+=char(message[i]-s2[i]-s2[i-1]+'0'+'0');
        }
        cout<<s2<<endl;
        for(i=0;i<s1.length();i++)
            if(s1[i]>'1' || s1[i] < '0')
            {
                s1 = "NONE";
                break;
            }
        for(i=0;i<s2.length();i++)
            if(s2[i]>'1' || s2[i] < '0')
            {
                s2 = "NONE";
                break;
            }
        if(s1!="NONE")
        {
            if(s1[s1.length()-2]+s1[s1.length()-1]-'0'!=message[message.length()-1])
            {
                s1="NONE";
            }
        }
        if(s2!="NONE")
        {
            if(s2[s2.length()-2]+s2[s2.length()-1]-'0'!=message[message.length()-1])
            {
                s2="NONE";
            }
        }
        vector<string> res;
        res.push_back(s1);
        res.push_back(s2);
        return res;
    }
};

class PowerOutage
{
public:
    vector<int> v[50];
    int estimateTimeOut(vector <int> from, vector <int> to, vector <int> len)
    {
        int sum =0,i;
        for (i=0;i<len.size();i++)
            sum+=len[i]*2;
        for(i=0;i<50;i++)v[i].clear();
        for(i=0;i<len.size();i++)
        {
            v[from[i]].push_back(to[i]);
            v[from[i]].push_back(len[i]);
        }
        int maxlen=getmax(0);
        return sum-maxlen;
    }
    int getmax(int n)
    {
        int res = 0,tmp;
        for(int i=0;i<v[n].size();i+=2)
        {
            tmp=v[n][i+1]+getmax(v[n][i]);
            if (res<tmp)res=tmp;
        }
        return res;
    }
};

int main()
{
    return 0;
}
