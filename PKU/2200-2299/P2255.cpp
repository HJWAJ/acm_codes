#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 26

char  preorder[MAX+1],inorder[MAX+1],postorder[MAX+1];

int pos(int pos0)
{
	for(int i=0;i<=MAX;i++)
		if(preorder[pos0]==inorder[i])
		{
            return i;
		    break;
        }
}

void calculate(int pre1,int pre2,int in1,int in2,int post1,int post2)
{
    int position; 
    if(pre1>pre2||post1>post2) return;
    postorder[post2]=preorder[pre1];
	position=pos(pre1);
    calculate(pre1+1,pre1+position-in1,in1,position-1,post1,post1+position-in1-1);
	calculate(pre1+position+1-in1,pre2,position+1,in2,post1+position-in1,post2-1);
}

int main()
{   
	int len;
    while (cin>>preorder>>inorder)
    {
		memset(postorder,'\0',sizeof(postorder));
		len=strlen(inorder);
		calculate(0,len,0,len,0,len-1);
	    for(int i=0;i<len;i++)cout<<postorder[i];
		memset(preorder,'\0',sizeof(preorder));
        memset(inorder,'\0',sizeof(inorder));
		cout<<endl;
	}
	
    return 0;
}


