#include<iostream>
#include<string>
using namespace std;

int main()
{
    enum Haab{pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu,uayet} month[10000];
    int n;
    char dot;
    char mon[10000][10];
    int m[18];
    int dname[10000];
    char daysname[10000][10];
    
    int d,d1[10000],d2[10000],y1[10000],y2[10000];
    
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>d1[i]>>dot>>mon[i]>>y1[i];
        
    for(int i=0;i<n;i++)
    {if(strcmp(mon[i],"pop")==0)month[i]=pop;
    if(strcmp(mon[i],"no")==0)month[i]=no;
    if(strcmp(mon[i],"zip")==0)month[i]=zip;
    if(strcmp(mon[i],"zotz")==0)month[i]=zotz;
    if(strcmp(mon[i],"tzec")==0)month[i]=tzec;
    if(strcmp(mon[i],"xul")==0)month[i]=xul;
    if(strcmp(mon[i],"yoxkin")==0)month[i]=yoxkin;
    if(strcmp(mon[i],"mol")==0)month[i]=mol;
    if(strcmp(mon[i],"chen")==0)month[i]=chen;
    if(strcmp(mon[i],"yax")==0)month[i]=yax;
    if(strcmp(mon[i],"zac")==0)month[i]=zac;
    if(strcmp(mon[i],"ceh")==0)month[i]=ceh;
    if(strcmp(mon[i],"mac")==0)month[i]=mac;
    if(strcmp(mon[i],"kankin")==0)month[i]=kankin;
    if(strcmp(mon[i],"muan")==0)month[i]=muan;
    if(strcmp(mon[i],"pax")==0)month[i]=pax;
    if(strcmp(mon[i],"koyab")==0)month[i]=koyab;
    if(strcmp(mon[i],"cumhu")==0)month[i]=cumhu;
    if(strcmp(mon[i],"uayet")==0)month[i]=uayet;  
    }
        
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        {d=365*y1[i]+20*month[i]+d1[i];
         d2[i]=d%13+1;
         dname[i]=d%20;
         y2[i]=d/260;
         switch(dname[i]){
         case 0:strcpy(daysname[i],"imix");break;
         case 1:strcpy(daysname[i],"ik");break;
         case 2:strcpy(daysname[i],"akbal");break;
         case 3:strcpy(daysname[i],"kan");break;
         case 4:strcpy(daysname[i],"chicchan");break;
         case 5:strcpy(daysname[i],"cimi");break;
         case 6:strcpy(daysname[i],"manik");break;
         case 7:strcpy(daysname[i],"lamat");break;
         case 8:strcpy(daysname[i],"muluk");break;
         case 9:strcpy(daysname[i],"ok");break;
         case 10:strcpy(daysname[i],"chuen");break;
         case 11:strcpy(daysname[i],"eb");break;
         case 12:strcpy(daysname[i],"ben");break;
         case 13:strcpy(daysname[i],"ix");break;
         case 14:strcpy(daysname[i],"mem");break;
         case 15:strcpy(daysname[i],"cib");break;
         case 16:strcpy(daysname[i],"caban");break;
         case 17:strcpy(daysname[i],"eznab");break;
         case 18:strcpy(daysname[i],"canac");break;
         case 19:strcpy(daysname[i],"ahau");break;
         }
         cout<<d2[i]<<" "<<daysname[i]<<" "<<y2[i]<<endl;}
    
    system("pause");
    return 0;    
}
