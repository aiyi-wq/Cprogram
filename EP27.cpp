/*************************************************************************
	> File Name: EP27.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Jun 2020 03:15:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 2000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int get_len(int a, int b) {
    int cnt = 0;
    for (int n = 0; n < max_n; n++) {
        int tmp = n * n + a * n + b;
        if (tmp < 0) break;
        if (is_prime[tmp]) break;
        cnt++;
    }
    return cnt;
}

int main() {
    init();
    long long x, y, len = 0;
    for (int b = 2; b <= 1000; b++) {
        if (is_prime[b]) continue;
        for (int a = -999; a < 1000; a++) {
            if (a + b + 1 < 2 || is_prime[a + b + 1]) continue;
            int tmp = get_len(a, b);
            if (tmp > len) {
                len = tmp;
                x = a;
                y = b;
            }
        }
    }
    cout << x * y << endl;
    return 0;
}
