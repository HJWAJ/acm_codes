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
#include<sstream>
using namespace std;
char s[1005];
vector<int> v;
int numsta[1005];
char optsta[1005]="=";
int numtop=0,opttop=1;
int pow3(int n)
{
    int res=1;
    for(int i=0;i<n;i++)res*=3;
    return res;
}
char cmp(char a,char b)
{
	if(a=='=')
    {
        if(b=='=')return '=';
		else return '<';
    }
    else if(a=='(')
    {
        if(b==')')return '=';
        return '<';
    }
    else if(a==')')return '<';
    else if(a=='+' || a=='-' || a=='*')
    {
        if(b=='(')return '<';
        else return '>';
    }
    else return '>';
}
int calc(int a,int b,char op)
{
	switch(op)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		default: return 0;
	}
}
bool isopt(char ch)
{
    char op[]="+-*=()";
    int i;
	for(i=0;i<6;i++)
        if(op[i]==ch)return 1;
	return 0;
}
void print()
{
    int i;
    printf("%d\n",numtop);
    for(i=0;i<numtop;i++)printf("%d ",numsta[i]);
    puts("");
    printf("%d\n",opttop);
    for(i=0;i<opttop;i++)printf("%c",optsta[i]);
    puts("");
}
int calcexp(char s[])
{
    int i=0,num=0;
	while(s[i]!='\0' || opttop!=0)
	{
		if(!isopt(s[i]))
		{
			num=0;
			while(!isopt(s[i]))
			{
				num*=10;
				num+=(s[i]-'0');
				i++;
			}
			numsta[numtop]=num;
			numtop++;
			//print();
		}
		else
		{
			switch(cmp(optsta[opttop-1],s[i]))
			{
				case '<':
                    optsta[opttop]=s[i];
                    opttop++;
					i++;
					break;
				case '=':
					opttop--;
					i++;
					break;
				case '>':
					int a=numsta[numtop-1];
					numtop--;
					int b=numsta[numtop-1];
					numtop--;
					numsta[numtop]=calc(b,a,optsta[opttop-1]);
					numtop++;
					opttop--;
					break;
			}
			//print();
		}
	}
    optsta[opttop]='=';
    opttop=1;
    numtop--;
    if(numtop!=0)cout<<"!!!"<<endl;
    return numsta[0];
}
void gao(char s[])
{
    char tmp[1005];
    memset(tmp,0,sizeof(tmp));
    int i=0,j=0;
    while(s[i]==' ')i++;
    while(s[i])
    {
        if(s[i]=='(' && tmp[j-1]!=' ' && tmp[j-1]!='(' && j)
        {
            tmp[j++]=' ';
            tmp[j++]='(';
            i++;
        }
        else if(s[i]==')' && tmp[j-1]==' ')
        {
            tmp[j-1]=')';
            i++;
        }
        else if(s[i]!=' ')
        {
            if(tmp[j-1]==')' && s[i]!=')')tmp[j++]=' ';
            tmp[j++]=s[i++];
        }
        else if(s[i]==' ' && tmp[j-1]!=' ')
        {
            if(tmp[j-1]=='(')i++;
            else tmp[j++]=s[i++];
        }
        else i++;
    }
    if(tmp[j-1]==' ')tmp[j-1]='\0';
    memmove(s,tmp,j+1);
}
int main()
{
    //freopen("1.txt","w",stdout);
    int n,len,num,sum,tmp,tt=0,i,j,ch;
    while(scanf("%d",&n) && n)
    {
        tt++;
        v.clear();
        ch=getchar();
        while(ch==' ' || ch=='=')ch=getchar();
        s[0]=ch;
        gets(s+1);
        //puts(s);
        gao(s);
        //puts(s);
        len=strlen(s);
        s[len]='=';
        s[len+1]='\0';
        len++;
        num=0;
        for(i=0;i<len;i++)
            if(s[i]==' ')
            {
                num++;
                v.push_back(i);
            }
        sum=pow3(num);
        for(i=0;i<sum;i++)
        {
            tmp=i;
            for(j=0;j<v.size();j++)
            {
                if(tmp%3==0)s[v[j]]='+';
                else if(tmp%3==1)s[v[j]]='-';
                else s[v[j]]='*';
                tmp/=3;
            }
            if(calcexp(s)==n)
            {
                printf("Equation #%d:\n%d=",tt,n);
                s[len-1]='\0';
                puts(s);
                break;
            }
        }
        if(i==sum)
        {
            printf("Equation #%d:\n",tt);
            puts("Impossible");
        }
        puts("");
    }
    return 0;
}
