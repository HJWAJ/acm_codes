#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[4][1000],str[1000][100];      //s��������4���ַ���; str���������ַ��� 
    int a[26],i,j,len[4],max=0;          //len��������4���ַ�������; a���ÿ����ĸ���ֵĴ��� 
    memset(a,0,sizeof(a));
    memset(str,' ',sizeof(str));
    for(i=0;i<4;i++)                     //���벢ͳ��ÿ����ĸ���ֵĴ��� 
    {
        cin.getline(s[i],1000);
        len[i]=strlen(s[i]);
        for(j=0;j<len[i];j++)
        {
            if(s[i][j]>='A' && s[i][j]<='Z')a[s[i][j]-'A']++;                     
        }
    }
    
    for(i=0;i<26;i++)       //�ҳ����ִ���������ĸ�Ĵ�����ȷ����������� 
    {
        if(max<a[i])max=a[i];
    }
    
    for(i=0;i<max;i++)       //�ж�ÿ��������ĳһ�д���'*'����' ' 
    {   
        for(j=0;j<26;j++)
        {
            if(a[j]>0)
            {
                str[i][j*2]='*';
                a[j]--;           
            }
            else str[i][j*2]=' ';
            str[i][j*2+1]=' ';                
        }
    }
    
    for(i=0;i<max;i++)                        //ȥ������Ҫ��' ' 
    {   
        for(j=50;j>=0;j--)
        {   
            if(str[i][j]==' ')str[i][j]=0;
            else break;
        }
    }
    
    for(i=0;i<max;i++)                    //��� 
    {   
        for(j=0;j<51;j++)
            if(str[max-1-i][j]!=0)cout<<str[max-1-i][j];        //cout<<str[max-1-i][j];��WA;˵�����'\0'�Ͳ��������������� 
        cout<<endl;
    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
    
    system("pause");
    return 0;
}
