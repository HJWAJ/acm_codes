#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

int t;
int f2[10001];
int N;
int K;
int temp;
int idx;
int counter ;
stack<int> st;
bool needed = 0;

int main () {
	memset(f2, 0, sizeof(f2));
	scanf("%d%d",&N,&K);
	
	counter = 0;
	idx = 0;
	for (int i = 1; i <= K; i++) {
		scanf("%d", &temp);
		for (int j = 1; j <= temp; j++) {
			 counter++;		
			 scanf("%d", &t);
			 f2[t] = counter;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (f2[i]!=0 && f2[i]!=i) {
			st.push(i);
			idx = f2[i];
			while (f2[idx] != 0 && idx != i) {
				st.push(idx);
				idx = f2[idx];
			}
			if (f2[idx] == 0) {
				while (!st.empty()) {
					temp = st.top();
					f2[f2[temp]] = f2[temp];
					printf("%d%c%d", temp, ' ', f2[temp]);
					printf("\n");
					needed = 1;
					st.pop();
				}
				f2[i] = 0;
			}
			else if (idx == i) {
				int free;
				int x;
				for (x = N; f2[x]!=0; x--){}
				free = x;
				temp = st.top();
				printf("%d%c%d", temp, ' ', free);
				printf("\n");
				needed = 1;
				st.pop();
				while (!st.empty()) {
					temp = st.top();
					f2[f2[temp]] = f2[temp];
					printf("%d%c%d", temp, ' ', f2[temp]);
					printf("\n");
					needed = 1;
					st.pop();
				}
				f2[i] = i;
				printf("%d%c%d", free, ' ', i);
				printf("\n");
				needed = 1;
			}
		}
		
	}
	if (needed == 0) printf("No optimization needed\n");
	return 0;
}