/*************************************************************************
	> File Name: EP12.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 24 May 2020 06:56:12 PM CST
 ************************************************************************/
#include <stdio.h>
#define max_n 1000000

int prime[max_n + 5] = {0};
int f[max_n + 5] = {0};
int cnt[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if(!prime[i]) { 
            prime[++prime[0]] = i;
            f[i] = 2;
            cnt[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                f[prime[j] * i] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                cnt[prime[j] * i] = cnt[i] + 1;
                break;
            } else {
                cnt[prime[j] * i] = 1;
                f[prime[j] * i] = f[prime[j]] * f[i];
            }
        }
    }
    return ;
}

int main() {
    init();
 /*   for (int i = 2; i <= 100; i++) {
        printf("f[%d] = %d\n", i, f[i]);
    }
    printf("\n");*/
    int n = 1, fac = 0;
    while (fac <= 500) {
        n++;
        if (n & 1) {
            fac = f[n] * f[(n + 1) >> 1];
        } else {
            fac = f[n >> 1] * f[n + 1];
        }
    }
    printf("%d\n", n * (n + 1) / 2);
    return 0;
}
