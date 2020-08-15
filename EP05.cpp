/*************************************************************************
	> File Name: EP05.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 15 Jul 2020 08:17:26 AM CST
 ************************************************************************/
#include <stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int ans = 1;
    for (int i = 1; i <= 20; ++i) {
        ans *= i / gcd(ans, i);
    }
    printf("%d\n", ans);
    return 0;
}
