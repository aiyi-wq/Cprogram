/*************************************************************************
	> File Name: EP24.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 31 May 2020 07:33:54 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 10
#define max_m 1000000

int f[max_n + 5];
int num[max_n + 5];

void init() {
    f[0] = 1;
    num[0] = 1;
    for (int i = 1; i < max_n; i++) {
        f[i] = i * f[i - 1];
        num[i] = 1;
    }
    return ;
}

int get_num(int k, int val, int &x) {
    int step = k / val;
    x = 0;
    for (int t = 0; t <= step; x += (t <= step)) {
        t += num[x];
    }
    num[x] = 0;
    k %= val;
    return k;
}

int main() {
    init();
    int k = max_m - 1;
    for (int i = max_n - 1; i >= 0; i--) {
        int x;
        k = get_num(k, f[i], x);
        cout << x;
    }
    cout << endl;
    return 0;
}
