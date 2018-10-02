#include<iostream>
#include<cstdio>
#include<cmath>
int main()
{
	int i,k,sum = 0,j = 0;
	char a[11] = {0};
	scanf("%s",a);
	for(i = 0;i<10;i++)
	{
		if(a[i] == 'X')a[i] = 10 + '0';
		if(a[i] == '?')k = i;
		else sum = sum + (a[i] - '0') * (10 - i);
	}
	if(k == 9)
	{
		for(i = 0;i<=10;i++)
		{
			if((sum + i*(10 - k))%11 == 0)
			{
				if(i == 10 && k == 9)
				{
					printf("X\n");break;			
				}
				else if(i == 10 && k!= 9)
				{
					printf("-1\n");break;
				}
				else if(i!= 10)
				{
					printf("%d\n",i);break;
                }
            }
		}
		if(i == 11)printf("-1\n");
	}
	else
	{
		for(i = 0;i<=9;i++)
		{
			sum = sum + i*(10 - k);
			if(sum%11 == 0)
			{
				if(i == 10)
				{
					printf("X\n");
                    break;			
				}
				else
				{
					printf("%d\n",i);
                    break;				
				}
			}
			sum = sum - i*(10 - k);
		}
		if(i == 10)printf("-1\n");	
	}

    system("pause");
	return 0;
}
