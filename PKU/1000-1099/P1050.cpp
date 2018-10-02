#include<iostream>
using namespace std;

int main()
{
    int n,i,j,k,m;
    int max=-999999,s,sum;
    int a[100][100],colsum[101][101];
    int col[101];

    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];

    for(j=0;j<n;j++)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            s+=a[i][j];
            colsum[i][j]=s;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
            {
                if(i==0) col[k]=colsum[j][k];
                else col[k]=colsum[j][k]-colsum[i-1][k];
            }
            for(m=0;m<n;m++)
            {
                if(sum<0) sum=0;
                sum+=col[m];
                if(sum>max) max=sum;
            }
        }
    }
    cout<<max<<endl;
    
    system("pause");
    return 0;
}
