#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
	int m,n;
	set<string> s;
	set<string>::iterator it;
	char book[1000][61];
	memset(book,0,sizeof(book));
	char str[100];
	cin>>m>>n;
	getchar();
	for(int i=0;i<m;i++){gets(str);s.insert(str);}

	int k=0;
	for(it=s.begin();it!=s.end();it++)
	{
		strcpy(book[k],(*it).c_str());
		book[k][strlen(book[k])]='\0';
		k++;
	}

	int sum=0;
	while(n--)
	{
		gets(str);

		int j;int len;
		int slen=strlen(str);
		int i=0;
		while(i<m && book[i++][0]<str[0]);	//加入搜索提示,加快搜索
		if(book[--i][0]>str[0]) continue;
		for(;i<m;i++)
		{
			int ll=strlen(book[i]);
			len=ll>slen?slen:ll;
			for(j=0;j<len;j++)
			{
				if(book[i][j]!=str[j])	break;
			}
			if(j==len) {sum++;break;}
		}
	}
	cout<<sum<<endl;
	return 0;
}

