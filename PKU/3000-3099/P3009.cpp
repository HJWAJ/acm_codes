#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int map[20][20],w,h,moves;

void DFS(int i,int j,int a,int b,int step)
{
	int x=i,y=j;//����ʯͷ�ĵ�ǰλ��
	if(step<moves&&i-1>=0&&(map[i-1][j]==0||map[i-1][j]==3))
	{//ʯͷ���������ƶ�������
		while(i-1>=0&&map[i-1][j]==0)i--;//������Ϸ����4�����ƶ�
		if(i>0&&map[i-1][j]==3){moves=step;}//����Ŀ�ĵ�
		if(i>0&&map[i-1][j]==1)//������ľ
		{
			map[i-1][j]=0;//��ľ��ʧ
			DFS(i,j,i-1,j,step+1);//�����ƶ�
		}
	}
	i=x;
	j=y;
	if(step<moves&&j-1>=0&&(map[i][j-1]==0||map[i][j-1]==3))
	{//ʯͷ���������ƶ�������
		while(j-1>=0&&map[i][j-1]==0)j--;//������Ϸ����4�����ƶ�
		if(j>0&&map[i][j-1]==3){moves=step;}//����Ŀ�ĵ�
		if(j>0&&map[i][j-1]==1)//������ľ
		{
			map[i][j-1]=0;//��ľ��ʧ
			DFS(i,j,i,j-1,step+1);//�����ƶ�
		}
	}
	i=x;
	j=y;
	if(step<moves&&i+1<h&&(map[i+1][j]==0||map[i+1][j]==3))
	{//ʯͷ���������ƶ�������
		while(i+1<h&&map[i+1][j]==0)i++;//������Ϸ����4�����ƶ�
		if(i<h-1&&map[i+1][j]==3){moves=step;}//����Ŀ�ĵ�
		if(i<h-1&&map[i+1][j]==1)//������ľ
		{
			map[i+1][j]=0;//��ľ��ʧ
			DFS(i,j,i+1,j,step+1);//�����ƶ�
		}
	}
	i=x;
	j=y;
	if(step<moves&&j+1<w&&(map[i][j+1]==0||map[i][j+1]==3))
	{//ʯͷ���������ƶ�������
		while(j+1<w&&map[i][j+1]==0)j++;//������Ϸ����4�����ƶ�
		if(j+1<w&&map[i][j+1]==3){moves=step;}//����Ŀ�ĵ�
		if(j+1<w&&map[i][j+1]==1)//������ľ
		{
			map[i][j+1]=0;//��ľ��ʧ
			DFS(i,j,i,j+1,step+1);//�����ƶ�
		}
	}
	map[a][b]=1;//��ԭ��ľ
}

int main()
{
	int i,j,a,b;
	while(1)
	{
		scanf("%d%d",&w,&h);
		if(w==0&&h==0)break;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
				{
					map[i][j]=0;//������ɿհ׵�
					a=i;//a��b��ʾ�������
					b=j;
				}
			}
		}
		moves=11;//�����ƶ�10��
		DFS(a,b,a,b,1);
		printf("%d\n",moves<11?moves:-1);
	}
	
	return 0;
}
