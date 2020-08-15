/*************************************************************************
	> File Name: EP-13.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 23 May 2020 02:52:32 PM CST
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#define max_n 53

char str[max_n + 5];
int ans[max_n + 5] = {1, 0};

int main() {
    for (int i = 0; i < 100; i++) {
        scanf("%s", str);
        int len = strlen(str);
        if (ans[0] < len) ans[0] = len;
        for (int i = 0; i < len; i++) {
            ans[len - i] += (str[i] - '0');
        }
        for (int i = 0; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    for (int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
