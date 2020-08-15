/*************************************************************************
	> File Name: EP44.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2020 10:33:44 PM CST
 ************************************************************************/
#include <stdio.h>
#include <inttypes.h>

typedef long long int1;

inline int1 P(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 binary_search(int1 (*func)(int1), int1 l, int1 r, int1 x) {
    int1 head = l, tail = r, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    int1 n = 2, D = INT32_MAX;
    while (P(n) - P(n - 1) < D) {
       int1 pk = P(n);
        for (int j = n - 1; j >= 1; j--) {
            int1 pj = P(j);
            if (pk - pj > D) break;
            int flag = 1;
            flag = flag &&(binary_search(P, 1, pk + pj, pk + pj));
            flag = flag && (binary_search(P, 1, pk - pj, pk - pj));
            if (!flag) continue;
            D = pk - pj;
            printf("%lld - %lld = %lld\n", pk, pj, D);
        }
        n += 1;
    }
    printf("%lld\n", D);
    return 0;
}

