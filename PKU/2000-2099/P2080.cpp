#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,week,year400,year100,year4,year1,year,day,date[2];
    char s[10],month[3];
    cin>>n;
    while(n!=-1)
    {
        week=n%7;
        switch(week)
        {
            case 0: strcpy(s,"Saturday");break;
            case 1: strcpy(s,"Sunday");break;
            case 2: strcpy(s,"Monday");break;
            case 3: strcpy(s,"Tuesday");break;
            case 4: strcpy(s,"Wednesday");break;
            case 5: strcpy(s,"Thursday");break;
            case 6: strcpy(s,"Friday");break;       
        }
        
        n++;
        year400=n/146097;
        if(n%146097>36525)
        {
            year100=(n%146097-36525)/36524+1; 
            if((n%146097-36525)%36524>1460)
            {
                year4=((n%146097-36525)%36524-1460)/1461+1;
                if(((n%146097-36525)%36524-1460)%1461>=366)
                {
                    year1=(((n%146097-36525)%36524-1460)%1461-366)/365+1;
                    day=(((n%146097-36525)%36524-1460)%1461-366)%365;
                }
                else 
                {
                    year1=0;
                    day=((n%146097-36525)%36524-1460)%1461;
                }
            }
            else
            {
                year4=0;
                year1=(n%146097-36525)%36524/365;
                day=(n%146097-36525)%36524%365;
            }                
        }    
        else
        {
            year100=0;
            year4=n%146097/1461;
            if(n%146097%1461>366)
            {
                year1=(n%146097%1461-366)/365+1;
                day=(n%146097%1461-366)%365;
            }
            else 
            {
                year1=0;
                day=n%146097%1461;
            }
        }
        
        year=year400*400+year100*100+year4*4+year1;

        if((year%4==0 && year%100!=0) || year%400==0)
        {
            if(day-31<=0){strcpy(month,"01");date[0]=day/10;date[1]=day%10;}
            else if(day-60<=0){strcpy(month,"02");day-=31;date[0]=day/10;date[1]=day%10;}
            else if(day-91<=0){strcpy(month,"03");day-=60;date[0]=day/10;date[1]=day%10;}
            else if(day-121<=0){strcpy(month,"04");day-=91;date[0]=day/10;date[1]=day%10;}
            else if(day-152<=0){strcpy(month,"05");day-=121;date[0]=day/10;date[1]=day%10;}
            else if(day-182<=0){strcpy(month,"06");day-=152;date[0]=day/10;date[1]=day%10;}
            else if(day-213<=0){strcpy(month,"07");day-=182;date[0]=day/10;date[1]=day%10;}
            else if(day-244<=0){strcpy(month,"08");day-=213;date[0]=day/10;date[1]=day%10;}
            else if(day-274<=0){strcpy(month,"09");day-=244;date[0]=day/10;date[1]=day%10;}
            else if(day-305<=0){strcpy(month,"10");day-=274;date[0]=day/10;date[1]=day%10;}
            else if(day-335<=0){strcpy(month,"11");day-=305;date[0]=day/10;date[1]=day%10;}
            else {strcpy(month,"12");day-=335;date[0]=day/10;date[1]=day%10;}       
        }
        else
        {
            if(day-31<=0){strcpy(month,"01");date[0]=day/10;date[1]=day%10;}
            else if(day-59<=0){strcpy(month,"02");day-=31;date[0]=day/10;date[1]=day%10;}
            else if(day-90<=0){strcpy(month,"03");day-=59;date[0]=day/10;date[1]=day%10;}
            else if(day-120<=0){strcpy(month,"04");day-=90;date[0]=day/10;date[1]=day%10;}
            else if(day-151<=0){strcpy(month,"05");day-=120;date[0]=day/10;date[1]=day%10;}
            else if(day-181<=0){strcpy(month,"06");day-=151;date[0]=day/10;date[1]=day%10;}
            else if(day-212<=0){strcpy(month,"07");day-=181;date[0]=day/10;date[1]=day%10;}
            else if(day-243<=0){strcpy(month,"08");day-=212;date[0]=day/10;date[1]=day%10;}
            else if(day-273<=0){strcpy(month,"09");day-=243;date[0]=day/10;date[1]=day%10;}
            else if(day-304<=0){strcpy(month,"10");day-=273;date[0]=day/10;date[1]=day%10;}
            else if(day-334<=0){strcpy(month,"11");day-=304;date[0]=day/10;date[1]=day%10;}
            else {strcpy(month,"12");day-=334;date[0]=day/10;date[1]=day%10;}   
        }
        if(date[0]==0 && date[1]==0){date[0]=3;date[1]=1;year--;strcpy(month,"12");}
        cout<<year+2000<<'-'<<month<<'-'<<date[0]<<date[1]<<' '<<s<<endl;
        cin>>n;            
    }
    
	system("pause");
	return 0;
}
