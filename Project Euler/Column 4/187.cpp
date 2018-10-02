//
//  main.cpp
//  test
//
//  Created by 华嘉炜 on 15/7/16.
//  Copyright (c) 2015年 华嘉炜. All rights reserved.
//  project euler 187
//

#include <iostream>
using namespace std;

int prime[2000005];
bool bo[60000000];
bool ok[100000001];

int prime_table() {
    int i, j;
    bo[0] = bo[1] = 1;
    for(int i = 2; i <= 7500; i++) {
        if (!bo[i])
            for (j = 2; (long long)j * i < 56250000; j++)
                bo[j * i] = 1;
    }
    int prime_cnt = 0;
    for (i = 0; i < 50000000; i++)
        if (!bo[i]) {
            prime[prime_cnt++] = i;
        }
    return prime_cnt;
}

int main(int argc, const char * argv[]) {
    int prime_cnt = prime_table();
    int cnt = 0;
    for (int i = 0; i < prime_cnt; i++)
        for (int j = 0; j < prime_cnt && (long long)prime[i] * prime[j] < 100000000; j++)
            ok[prime[i] * prime[j]] = 1;
    for (int i = 0; i < 100000000; i++)
        if (ok[i])
            cnt++;
    cout << cnt << endl;
    return 0;
}
