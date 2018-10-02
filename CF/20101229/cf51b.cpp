#include<iostream>
#include<algorithm>
#include<stack>
#include<string.h>
using namespace std;

int main() {
	char s[5005], input[5005];
	int i, count[1000], l, tmp, n, len;
	while(scanf("%s",input)!=EOF) {
		strcat(s, input);
	}
	l = strlen(s);
	stack<int> t;
	len = 0;
	for (i = 0; i < l - 6; i++) {
        if(s[i] != '/' && s[i+1] == 't' && s[i+2] == 'a' && 
        s[i+3] == 'b' && s[i+4] == 'l' && s[i+5] == 'e') t.push(1);
        if(s[i] != '/' && s[i+1] == 't' && s[i+2] == 'd') t.push(2);
        if(s[i] == '/' && s[i+1] == 't' && s[i+2] == 'a' &&
        s[i+3] =='b' && s[i+4] == 'l' && s[i+5] == 'e') {
            tmp = t.top();
            n = 0;  
            while(tmp == 2)        
            {
                 n++;
                 t.pop();
                 tmp = t.top();
            }
            t.pop();
            count[len++] = n;         
        }
    }
    sort(count, count + len);
    for (i = 0; i < len - 1; i++) printf("%d ",count[i]);
    printf("%d\n",count[len-1]);
	system("pause");
	return 0;
}
