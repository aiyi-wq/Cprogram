/*************************************************************************
	> File Name: EP35.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 May 2020 06:47:20 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
void init() {
    for (int i = 2; i < max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return ;
}

int is_val(int n) {
    int a, b;
    int digit = floor(log10(n)) + 1;
    int h = pow(10, digit - 1);
    for (int i = 1; i <= digit - 1; i++) {
        a = n / pow(10, i);
        if (is_prime[a]) return 0;
        b = n % h;
        if (is_prime[b]) return 0;
        h /= 10;
    }
    return n;
}

int main() {
    int cnt = 11, sum = 0;
    init();
    for (int i = 5; i <= prime[0] && cnt; i++) {
        sum += (is_val(prime[i]));
        cnt--;
    }
    cout << sum << endl;
    return 0;
}
