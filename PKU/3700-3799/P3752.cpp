#include<iostream>
using namespace std;

int main ()
{
    char matrix[100][100];
    int m,n,i=0,j=0,next_i=0,next_j=0,x=0,count=0,letter=0;
    int direct[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
    
    cin>>m>>n;
    memset(matrix,'0',sizeof(matrix));
    while(count<m*n)
    {
        matrix[i][j]='A'+letter%26;
        next_i=i+direct[x][0];
        next_j=j+direct[x][1];
        if (next_i==m || next_j==n || next_i<0 || next_j<0 || matrix[next_i][next_j]!='0')
        {
            x=(x+1)%4;
            next_i=i+direct[x][0];
            next_j=j+direct[x][1];
        }
        i=next_i;
        j=next_j;
        letter++;
        count++;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<"   "<<char(matrix[i][j]);
        cout<<endl;
    }
    
    system("pause");
    return 0;
}
