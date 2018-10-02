#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char line[200];
int reg[30][30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int c=0;
	while(scanf("%s",line)!=EOF&&line[0]!='#')
	{
		memset(reg,0,sizeof(reg));
		int i,j,k,t;
		for(k=0,i=0;line[k];++k)
		{
			if(line[k]=='-')
				for(;i<k;++i)
					for(j=k+1;line[j]&&line[j]!=',';++j)
						reg[line[i]-'A'][line[j]-'a']=0;
			if(line[k]=='+')
				for(;i<k;++i)
					for(j=k+1;line[j]&&line[j]!=',';++j)
						reg[line[i]-'A'][line[j]-'a']=1;
			if(line[k]=='=')
				for(;i<k;++i)
				{
					memset(reg[line[i]-'A'],0,sizeof(reg[line[i]-'A']));
					for(j=k+1;line[j]&&line[j]!=',';++j)
						reg[line[i]-'A'][line[j]-'a']=1;
				}
			if(line[k]==',')
				i=k+1;	
		}
		printf("%d:",++c);
		for(i=0;i<26;++i)
		{
			k=0;
			for(j=0;j<26;++j)
				k+=reg[i][j];
			if(k!=0)
			{
				printf("%c",'A'+i);
				for(j=i+1;j<26;++j)
				{
					k=0;
					for(t=0;t<26;++t)
						k+=reg[j][t];
					if(k!=0)
					{
						if(memcmp(reg[i],reg[j],sizeof(reg[i]))==0)
						{
							printf("%c",'A'+j);
							memset(reg[j],0,sizeof(reg[j]));
						}
						else
							break;
					}
				}
				for(j=0;j<26;++j)
					if(reg[i][j])printf("%c",'a'+j);
			}
		}
		printf("\n");
	}
	return 0;
}
