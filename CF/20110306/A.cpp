#include<iostream>  
using namespace std;  
int main()  
{      
       int a,b,c,d,e,f;      
       cin>>a>>b>>c>>d>>e>>f;      
       if(c==0&&d!=0)      
       {          
                  cout<<"Ron";
                  return 0;      
       }      
       if(a==0&&d!=0&&b!=0)      
       {          cout<<"Ron";
       return 0;      
       }      
       if(f==0)      
       {          
                  cout<<"Hermione";
                  return 0;      
       }      
       if(e==0&&f!=0&&b!=0&&d!=0)      
       {          cout<<"Ron";
       return 0;      
       }      
       double ans=(double)f*d*b*100.0/e/c/a;      
       if(ans>100.0)cout<<"Ron";      
       else cout<<"Hermione";return 0;        
       return 0;  
}
