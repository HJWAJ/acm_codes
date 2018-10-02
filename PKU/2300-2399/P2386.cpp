#include<iostream>
#include<cstring>

using namespace std;

const int MAX=101;
char map[MAX][MAX],lake[MAX][MAX];
int n,m;
int LakeNum,rear,front;
int move[8][2]=
    {
        {-1,0},
        {-1,1},
		{-1,-1},
		{0,1},
		{0,-1},
		{1,0},
		{1,-1},
		{1,1},
        
    };

struct queuesort{
	int x;
	int y;
};

queuesort queue[MAX*MAX];





int main()
{

	int i,j,i1;
    char temp;

    cin>>n>>m;

    for (i=0;i<n;i++)
		for (j=0;j<m;j++)
		{
			cin>>temp;
			if (temp=='W') { map[i][j]=1;}
			else if (temp=='.') { map[i][j]=-1;}
		}



    memset(lake,0,sizeof(lake));

	LakeNum=0;

	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
		{
          if ( (map[i][j]==1) && (lake[i][j]==0) )
		  { 
			  LakeNum++;   lake[i][j]=1;
			  memset(queue,0,sizeof(queue));
			  queue[0].x=i; queue[0].y=j;
			  rear=0;
			  front=0;

			  while (rear<=front)
			  {
                for (i1=0;i1<8;i1++)
				{
					if( (queue[rear].x+move[i1][0]>=0) &&
					   (queue[rear].x+move[i1][0]<=n) &&
                       (queue[rear].y+move[i1][1]>=0) &&
                       (queue[rear].y+move[i1][1]<=m) )
					{
					   if ((map[queue[rear].x+move[i1][0]][queue[rear].y+move[i1][1]]==1) 
						 && (lake[queue[rear].x+move[i1][0]][queue[rear].y+move[i1][1]]==0))
					   {
                        front++;
						lake[queue[rear].x+move[i1][0]][queue[rear].y+move[i1][1]]=1;
						queue[front].x=queue[rear].x+move[i1][0];
						queue[front].y=queue[rear].y+move[i1][1];
					    
					   }

					}
				}

               rear++;
			  }
				

		  }


		}
    cout<<LakeNum<<endl;
    return 0;
}
