/*************************************************************************
	> File Name: EP25.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 May 2020 07:07:01 PM CST
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#define max_n 1000

int fib[3][max_n + 5] = {{0, 1}, {1, 1}, {1, 1}};

int main() {
    int n = 2;
    while (fib[n % 3][0] < max_n) {
        n++;
        int *a = fib[n % 3], *b = fib[(n - 1) % 3], *c = fib[(n - 2) % 3];
        for (int i = 1; i <= b[0]; i++) {
            a[i] = b[i] + c[i];
        }
        a[0] = b[0];
        for (int i = 1; i <= a[0];i++) {
            if (a[i] < 10) continue;
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            a[0] += (i == a[0]);
        }
    }
    printf("%d\n", n);
    return 0;
}
