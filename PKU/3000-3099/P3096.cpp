#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<set>
using namespace std;
struct cmp
{
    bool operator()(const char *s1,const char *s2)const
    {
        return strcmp(s1,s2)<0;
    }
};
set<string> sset;
bool isUnique(char s[],int dis)
{
    sset.clear();
    pair<set<string>::iterator,bool> p;
    int i,len=strlen(s);
    string tmp;
    for(i=0;i+dis+1<len;i++)
    {
        tmp.push_back(s[i]);
        tmp.push_back(s[i+dis+1]);
        p=sset.insert(tmp);
        if(!p.second)return false;
        tmp.clear();
    }
    return true;
}
bool isSurprise(char s[])
{
    int len=strlen(s),i;
    for(i=0;i<len-2;i++)
        if(!isUnique(s,i))return false;
    return true;
}
int main()
{
    char s[100];
    while(scanf("%s",s) && strcmp(s,"*"))
    {
        if(isSurprise(s))printf("%s is surprising.\n",s);
        else printf("%s is NOT surprising.\n",s);
    }
    return 0;
}
