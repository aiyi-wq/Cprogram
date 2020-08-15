/*************************************************************************
	> File Name: EP33.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 30 May 2020 04:44:01 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

inline int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int is_val(int x, int y) {
    int x1 = x / 10, x2 = x % 10;
    int y1 = y / 10, y2 = y % 10;
    if (x1 == y2 && x * y1 == y * x2) return 1;
    if (x2 == y1 && x * y2 == y * x1) return 1;
    return 0;
}

int main() {
    int a = 1, b = 1;
    for (int i = 11; i < 50; i++) {
        for (int j = 98; j > i; j--) {
            if (!is_val(i, j)) continue;
            a *= i, b *= j;
           int c =  gcd(a, b);
            a /= c, b /= c;
        }
    }
    cout << b << endl;
    return 0;
}
