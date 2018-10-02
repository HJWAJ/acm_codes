#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const double EPS = 1e-5;
const int N = 1000;
int a[N], b[N]; double c[N];
double l, r, m;
int n, k;

void init(){
	for (int i=0;i<n;i++) scanf("%d", &a[i]);
	for (int i=0;i<n;i++) scanf("%d", &b[i]);
}

double f(double x){
	for (int i=0;i<n;i++)
		c[i] = a[i] - b[i]*x;
	sort(c, c+n);
	double res = 0;
	for (int i=k;i<n;i++)
		res += c[i];
	return res;
}

int main(){
	while (scanf("%d %d", &n, &k)==2 && n!=0){
		init(); l = 0; r = 1;
		while (l+EPS<r){
			m = (l+r) / 2;
			if (f(m) > 0) l = m;
			else r = m;
		}
		printf("%.0lf\n", l*100);
	}
}


