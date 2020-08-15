/*************************************************************************
	> File Name: EP47.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2020 02:45:01 PM CST
 ************************************************************************/
#include <stdio.h>
#define max_n 1000000

int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= max_n; j += i) {
            prime[j] += 1;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 2; ; i++) {
        int flag = 1;
        for (int j = 0;flag && j < 4; j++) {
            flag = flag && prime[i + j] == 4; 
        }
        if (!flag) continue;
        printf("%d\n", i);
        break;
    }
    return 0;
}
