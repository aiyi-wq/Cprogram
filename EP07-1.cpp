/*************************************************************************
	> File Name: EP07-1.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2020 02:26:16 PM CST
 ************************************************************************/
#include <stdio.h>//线性筛，时间复杂度为O(N)
#define max_n 200000

int prime[max_n + 5] = {0};

int main() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    printf("%d\n", prime[10001]);
    return 0;
}
