#include <iostream>
using namespace std;

int main()
{
	int n,x,y;
	scanf("%x,%d,%d",&n,&x,&y);
	n&=~(0<<x);
	n&=~(0<<(y-2));
	n|=(1<<y);
	n|=(1<<(y-1));
	printf("%x",n);
	system("pause");
    return 0;
}
