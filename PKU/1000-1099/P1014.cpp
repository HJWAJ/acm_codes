#include<iostream>
using namespace std;

int main()
{
    int a[6],sum,t=0,cnt[6],summ,i;
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5] && (a[0]!=0 || a[1]!=0 || a[2]!=0 || a[3]!=0 || a[4]!=0 || a[5]!=0))
    {
        t++;
        sum=0;
        for(i=0;i<6;i++)a[i]%=8;
        for(i=0;i<6;i++)
            sum=sum+(i+1)*a[i];
        if(sum%2==1)
        {
            cout<<"Collection #"<<t<<":"<<endl;
            cout<<"Can't be divided."<<endl; 
            cout<<endl;
            continue;           
        }
        else
        {
            for(cnt[0]=a[0];cnt[0]>=0;cnt[0]--)
                for(cnt[1]=a[1];cnt[1]>=0;cnt[1]--)
                    for(cnt[2]=a[2];cnt[2]>=0;cnt[2]--)
                        for(cnt[3]=a[3];cnt[3]>=0;cnt[3]--)
                            for(cnt[4]=a[4];cnt[4]>=0;cnt[4]--)
                                for(cnt[5]=a[5];cnt[5]>=0;cnt[5]--)
                                {
                                    summ=0;
                                    for(i=0;i<6;i++)
                                        summ=summ+cnt[i]*(i+1);
                                    if(summ==(sum/2))
                                    {
                                        cout<<"Collection #"<<t<<":"<<endl;
                                        cout<<"Can be divided."<<endl;
                                        goto label;
                                    }                                   
                                }    
        }   
        cout<<"Collection #"<<t<<":"<<endl;
        cout<<"Can't be divided."<<endl;
        label:cout<<endl;                              
    }
    
    system("pause");
    return 0;
}
