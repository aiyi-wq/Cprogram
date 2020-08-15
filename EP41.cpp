/*************************************************************************
	> File Name: EP41.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jun 2020 06:11:46 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<cmath>
#include<algorithm>
#define max_n 10000000

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

int add_to_num(int *num, int n) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = ret * 10 + num[i];
    }
    return ret;
}

int main() {
    init();
    int n = 7, ans = 0;
    int num[8];
    while (n && !ans) {
        for (int i = 0; i < n; i++) num[i] = n - i;
        do {
            int tmp = add_to_num(num, n);
            if (!is_prime[tmp]) ans = tmp;
        } while (prev_permutation(num, num + n) && !ans);
        n -= 1;
    }
    cout << ans << endl;
    return 0;
}
