/*************************************************************************
	> File Name: EP29.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Aug 2020 10:47:31 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

#define MAX_N 10000
#define MAX_M 100

//表示二元组
struct Tuple {
    int p, a;//p: 最小素因子，a: 幂次
} arr[MAX_N + 5][MAX_N];

int prime[MAX_M + 5] = {0};

void get_num(int a, int b, Tuple *temp) {
    int len = 0;//当前变量的起始位置
    while (a != 1) {
        int p_num = 0, pre = prime[a];//p_num记录 % 质因子的次数
        while (a % pre == 0) p_num++, a /= pre;
        temp[len].p = pre, temp[len].a = p_num * b;
        len++;
    }
    return ;
}

int main() {
    for (int i = 2; i <= MAX_M; i++) {
        if (prime[i]) continue;
        for (int j = i; j <= MAX_M; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
    int cnt = 0;
    for (int a = 2; a <= MAX_M; a++) {
        for (int b = 2; b <= MAX_M; b++) {
            Tuple temp[4] = {0};
            get_num(a, b, temp);
            int flag = 1;
            for (int i = 0; i < cnt; i++) {
                flag = memcmp(arr[i], temp, sizeof(temp));
            }
            if (flag == 0) continue;
            memcpy(arr[cnt++], temp, sizeof(temp));
        }
    }
    cout << cnt << endl;
    return 0;
}
