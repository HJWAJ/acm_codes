#include<iostream>
using namespace std;
const int Max=300000001;
int eu[Max];

void euler()
{
	int i,j;
	eu[1]=1;
	for(i=2;i<Max;i++)
		if(!eu[i])
			for(j=i;j<Max;j+=i)
			{
				if(!eu[j])eu[j]=j;
				eu[j]=eu[j]/i*(i-1);
			}
}

long long euler(long long n)
{
		long long m=1;
		for(long long i=2;(long long)i*i<=n;i++)
				if(!(n%i))
				{
						n/=i;
						m*=(i-1);
						while(!(n%i))
						{
								m*=i;
								n/=i;
						}
				}
		if(n!=1)
				m*=(n-1);
		return m;
}

int main()
{
    /*
    euler();
    cout<<"ok"<<endl;
    for (int i = 2; i < Max; i++)
    {
        if ((long long)eu[i] * 94744 < (long long)(i - 1) * 15499)
        {
            cout << i << endl;
            break;
        }
    }
    */
    // and found nothing. change to a server and change Max to 10e9 and will find answer 892371480 for seconds.
    /*
    for (int N = Max + 1; ; N++)
        if ((long long)euler(N) * 94744 < (long long)(N - 1) * 15499 )
            cout << N << endl;
    */
    // too slow.
    int step = 2*3*5*7*11*13;
    for (long long N = step; ; N+=step)
        if ((long long)euler(N) * 94744 < (long long)(N - 1) * 15499 )
        {
            cout << N << endl;
            break;
        }
    // fast to come out. something guess. to convince.
	return 0;
}
