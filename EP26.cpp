/*************************************************************************
	> File Name: EP26.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 31 May 2020 08:05:56 PM CST
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define max_n 1000

int keep[max_n + 5];

int get_len(int d) {
    memset(keep, 0, sizeof(keep));
    int r = 1, t = 1;
    while (r) {
        keep[r] = t;
        r *= 10;
        r %= d;
        t += 1;
        if (keep[r]) return t - keep[r];
    }
    return 0;
}

int main() {
    int ans = 0, len = 0;
    for (int i = 2; i < max_n; i++) {
        int tmp = get_len(i);
        if (tmp > len) {
            ans = i;
            len = tmp;
        }
    }
    cout << ans << " " << len << endl;
    return 0;
}
