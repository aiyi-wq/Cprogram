/*************************************************************************
	> File Name: EP10.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2020 02:36:03 PM CST
 ************************************************************************/
#include <stdio.h>
#define max_n 2000000

int prime[max_n + 5] = {0};

int main() {
    for(int i = 2; i < max_n; i++) {
        if(!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    long long sum = 0;
    for (int i = 1; i <= prime[0]; i++) {
        sum += prime[i];
    }
    printf("%lld\n", sum);
    return 0;
}
