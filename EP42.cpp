/*************************************************************************
	> File Name: EP42.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 May 2020 07:06:37 PM CST
 ************************************************************************/
#include <stdio.h>//<>包含的文件在stdio编译的文件里去找
#include "words.txt"//" "包含的文件从当前这个文件所在的目录去匹配

inline int triangle(int n) {
    return n * ( n + 1 ) / 2;
}

int binary_search(int (*func)(int), int l, int r, int x) {
    int head = l, tail = r, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return 1;
        if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}


int is_val(const char *str) {
    int sum = 0;
    for (int i = 0; str[i]; i++) {
        sum += (str[i] - 'A' + 1);
    }
    return binary_search(triangle, 1, sum, sum);
}


int main() {
    int n = sizeof(str) / 100, cnt = 0;//sizeof获得str数组的长度，/ 100 得到[]的值，即单词的个数
//    printf("n = %d\n", n);
//    printf("%s\n", str[n - 1]);
    for (int i = 0; i < n; i++) {
        cnt += (is_val(str[i]));
    }
    printf("%d\n", cnt);
    return 0;
}
