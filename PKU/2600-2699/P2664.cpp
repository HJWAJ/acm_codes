#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int k,m,c,r;
    char s1[100][5],s2[100][5];
    while(cin>>k && k!=0)
    {
        cin>>m;
        bool judge=0;
        int i,j;
        for(i=0;i<k;i++)cin>>s1[i];
        for(i=0;i<m;i++)
        {
            cin>>c>>r;
            int cnt=0;
            for(j=0;j<c;j++)
            {
                cin>>s2[j];
                for(int p=0;p<k;p++)
                    if(strcmp(s1[p],s2[j])==0)
                    {
                        cnt++;
                        break;
                    }
            }               
            if(cnt<r)
            {
                judge=1;         
            }
        }             
        if(judge==0)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }   
    
    system("pause");
    return 0;
}
