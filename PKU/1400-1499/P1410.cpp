#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,xs,ys,xe,ye,xl,yt,xr,yb;
    float d,xtemp,ytemp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>xs>>ys>>xe>>ye>>xl>>yt>>xr>>yb;
        if(xl>xr)swap(xl,xr);
        if(yb>yt)swap(yb,yt);
        
        if(xs>=xl && xs<=xr && xe>=xl && xe<=xr && ys>=yb && ys<=yt && ye>=yb && ye<=yt)cout<<"T"<<endl;
        else
        {
        if(xs==xe)
        {
            if((xs>=xl && xs<=xr && ys>=yb && ys<=yt) || (xs>=xl && xs<=xr && ye>=yb && ye<=yt) || (xs>=xl && xs<=xr && ys>=yt && ye<=yb) || (xs>=xl && xs<=xr && ys<=yb && ye>=yt))cout<<"T"<<endl;
            else cout<<"F"<<endl;          
        }
        else if(ys==ye)
        {
            if((ys>=yb && ys<=yt && xs>=xl && xs<=xr) || (ys>=yb && ys<=yt && xe>=xl && xe<=xr) || (ys>=yb && ys<=yt && xs>=xr && xe<=xl) || (ys>=yb && ys<=yt && xe>=xr && xs<=xl))cout<<"T"<<endl;
            else cout<<"F"<<endl;          
        }
        else
        {
            d=float(((ye-ys)*(xl+xr)/2+(xs-xe)*(yt+yb)/2+(xe-xs)*ye+(ys-ye)*xe)/sqrt(float((xs-xe)*(xs-xe)+(ys-ye)*(ys-ye))));
            d=fabs(d);
            //xtemp=(0.5*((xe-xs)*(xl+xr)+(ye-ys)*(yb+yt))*(xe-xs)+(ye-ys)*((xe-xs)*ye+(ys-ye)*xe))/((xs-xe)*(xs-xe)+(ys-ye)*(ys-ye));
            //ytemp=(0.5*((xe-xs)*(xl+xr)+(ye-ys)*(yb+yt))*(ye-ys)+(xe-xs)*((xe-xs)*ye+(ys-ye)*xe))/((xs-xe)*(xs-xe)+(ys-ye)*(ys-ye));
            if(d>sqrt(float((float((yt-yb)*(yt-yb))/4+float((xr-xl)*(xr-xl))/4)))) cout<<"F"<<endl;
            //else if(xtemp>xr || xtemp<xl || ytemp>yt || ytemp<yb)cout<<"F"<<endl;
            else if(xs>xr && xe>xr || xs<xl && xe<xl || ys>yt && ye>yt ||ys<yb && ye<yb)cout<<"F"<<endl;
            else cout<<"T"<<endl;
        }   
        }    
    }
    
    system("pause");
    return 0;
}
