#include<iostream>
using namespace std;

int main()
{
    int t,i,h,min;
    char p;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>h>>p>>min;
        if(min!=0)cout<<0<<endl;
        else if(h==0)cout<<12<<endl;
        else if(h==1)cout<<13<<endl;
        else if(h==2)cout<<14<<endl;
        else if(h==3)cout<<15<<endl;
        else if(h==4)cout<<16<<endl;
        else if(h==5)cout<<17<<endl;
        else if(h==6)cout<<18<<endl;
        else if(h==7)cout<<19<<endl;
        else if(h==8)cout<<20<<endl;
        else if(h==9)cout<<21<<endl;
        else if(h==10)cout<<22<<endl;
        else if(h==11)cout<<23<<endl;
        else if(h==12)cout<<24<<endl;
        else if(h==13)cout<<1<<endl;
        else if(h==14)cout<<2<<endl;
        else if(h==15)cout<<3<<endl;
        else if(h==16)cout<<4<<endl;
        else if(h==17)cout<<5<<endl;
        else if(h==18)cout<<6<<endl;
        else if(h==19)cout<<7<<endl;
        else if(h==20)cout<<8<<endl;
        else if(h==21)cout<<9<<endl;
        else if(h==22)cout<<10<<endl;
        else if(h==23)cout<<11<<endl;           
    }    
    system("pause");
    return 0;
}
