/*************************************************************************
	> File Name: EP45.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 31 May 2020 03:58:11 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 1000000

typedef long long ll;

ll Pen(ll n) {
    return n * (3 * n - 1) / 2;
}

ll Hex(ll n) {
    return n * (2 * n - 1);
}

int binary_search(ll (*func)(ll), ll n, ll x) {
    ll head = 1, tail = n, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    ll n = 144;
    while(1) {
        if (binary_search(Pen, 2 * n, Hex(n))) break;
        n++;
    }
    cout << Hex(n) << endl;
    return 0;
}
