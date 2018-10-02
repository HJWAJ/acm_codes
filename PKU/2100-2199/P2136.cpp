#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[4][1000],str[1000][100];      //s存放输入的4个字符串; str存放输出的字符串 
    int a[26],i,j,len[4],max=0;          //len存放输入的4个字符串长度; a存放每个字母出现的次数 
    memset(a,0,sizeof(a));
    memset(str,' ',sizeof(str));
    for(i=0;i<4;i++)                     //输入并统计每个字母出现的次数 
    {
        cin.getline(s[i],1000);
        len[i]=strlen(s[i]);
        for(j=0;j<len[i];j++)
        {
            if(s[i][j]>='A' && s[i][j]<='Z')a[s[i][j]-'A']++;                     
        }
    }
    
    for(i=0;i<26;i++)       //找出出现次数最多的字母的次数以确定输出的行数 
    {
        if(max<a[i])max=a[i];
    }
    
    for(i=0;i<max;i++)       //判断每个柱形在某一行处是'*'还是' ' 
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
    
    for(i=0;i<max;i++)                        //去除不需要的' ' 
    {   
        for(j=50;j>=0;j--)
        {   
            if(str[i][j]==' ')str[i][j]=0;
            else break;
        }
    }
    
    for(i=0;i<max;i++)                    //输出 
    {   
        for(j=0;j<51;j++)
            if(str[max-1-i][j]!=0)cout<<str[max-1-i][j];        //cout<<str[max-1-i][j];则WA;说明输出'\0'和不输出还是有区别的 
        cout<<endl;
    }
    cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"<<endl;
    
    system("pause");
    return 0;
}
