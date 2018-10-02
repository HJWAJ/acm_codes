#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char command[300][300],site[300][300];
    int p=0,q=1,t,i;
    strcpy(site[0],"http://www.acm.org/");
    cin>>command[p];
    while(strcmp(command[p],"QUIT")!=0)
    {
        if(strcmp(command[p],"VISIT")==0)
        {
            if(strcmp(command[p-1],"FORWARD")==0)q++;
            if(strcmp(command[p-1],"BACK")==0)q++;
            cin>>site[q];
            cout<<site[q];
            cout<<endl;
            q++;
            t=q; 
            for(i=q;i<100;i++)
                memset(site[i],0,sizeof(site[i]));                
        } 
        if(strcmp(command[p],"BACK")==0)
        {
            q--;
            if(strcmp(command[p-1],"VISIT")==0)q--;
            if(q<0){cout<<"Ignored"<<endl;q++;}
            else {cout<<site[q];cout<<endl;}
        }                      
        if(strcmp(command[p],"FORWARD")==0)
        {
            q++;
            if(strcmp(command[p-1],"VISIT")==0)q--;
            if(q>=t){cout<<"Ignored"<<endl;q--;}
            else {cout<<site[q];cout<<endl;}
        }    
        p++;        
        cin>>command[p];
    }
    
    system("pause");
    return 0;
}
