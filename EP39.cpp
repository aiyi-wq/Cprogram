/*************************************************************************
	> File Name: EP39.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 02 Jun 2020 08:41:34 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000

int cnt[max_n + 5] = {0};

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    for (int i = 1; i <= 33; i++) {
        for (int j = i + 1; j * j + i * i < 1000; j++) {
            if (gcd(i, j) - 1) continue;
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = j * j + i * i;
            for (int p = a + b + c; p <= max_n; p += (a + b + c)) {
                cnt[p] += 1;
            }
        }
    }
    int p = 1;
    for (int i = 1; i <= max_n; i++) {
        if (cnt[i] > cnt[p]) p = i;
    }
    cout << p << endl;
    return 0;
}
