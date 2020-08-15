/*************************************************************************
	> File Name: EP38.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 May 2020 03:43:23 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define max_n 10000

int digits(long long n) {
    if (n == 0) return 1;
    return floor(log10(n)) + 1;
}

long long calc(int x) {
    long long n = 0, ans = 0;
    while (digits(ans) < 9) {
        n += 1;
        ans = ans * pow(10, digits(n * x));
        ans += n * x;
    }
    if (digits(ans) - 9) return 0;
    int num[10] = {1, 0};
    long long tmp = ans;
    while (tmp) {
        if (num[tmp % 10]) return 0;
        num[tmp % 10] += 1;
        tmp /= 10;
    }
    return ans;
}

int main() {
    long long ans = 0;
    for (int i = 1; i < max_n; i++) {
        long long tmp = calc(i);
        ans = (tmp > ans ? tmp : ans);
    }
    cout << ans << endl;
    return 0;
}
