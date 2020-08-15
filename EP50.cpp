/*************************************************************************
	> File Name: EP50.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jun 2020 02:18:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

typedef long long ll;
int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
ll presum[max_n + 5] = {0};

void init() {
    for (int i = 2; i < max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
//前缀和
    for (int i = 1; i <= prime[0]; i++) {
        presum[i] = presum[i - 1] + prime[i];
    }
    return ;
}

int main() {
    int ans, len = 0;
    init();
    for (int i = 0; i < prime[0]; i++) {
        for (int j = i + 1; j <= prime[0]; j++) {
            ll tmp = presum[j] - presum[i];
            if (tmp < max_n && !is_prime[tmp] && j - i > len) {
                ans = tmp;
                len = j - i;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
