#include<iostream>
#include<string>
using namespace std;

int main()
{
    char input[100][1000],start[100][11],end[100][11];
    int i=0,a[100];
    
    cin.getline(start[i],11);
    cin.getline(input[i],1000);
    a[i]=strlen(input[i]);
    cin.getline(end[i],11);
    while(strcmp(start[i],"ENDOFINPUT")!=0)
    {
        i++;
        cin.getline(start[i],11);
        if(strcmp(start[i],"ENDOFINPUT")==0)break;
        cin.getline(input[i],1000);
        a[i]=strlen(input[i]);
        cin.getline(end[i],11);                                    
    }
        
    for(int m=0;m<i;m++)
    {
        
        for(int n=0;n<1000;n++)
        {
            if(input[m][n]>'E'&&input[m][n]<='Z')input[m][n]-=5;
            else if(input[m][n]>='A'&&input[m][n]<='E')input[m][n]+=21;
                                                  
        }        
    }
    
    for(int m=0;m<i;m++)
    {
         
         for(int n=0;n<a[m];n++)
        cout<<input[m][n]; 
        cout<<endl;      
    }

    system("pause");
    return 0;
}
