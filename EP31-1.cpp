/*************************************************************************
	> File Name: EP31-1.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Jul 2020 05:57:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 8
#define max_m 200

int f[max_n + 5][max_m + 5];//用二维数组表示f(i, j)
int w[max_n + 5] = {1, 2, 5, 10, 20, 50, 100, 200}//总共八种面值的硬币

int main() {
    for (int i = 0; i < max_n; ++i) {
        f[i][0] = 1;
        f[i][w[i]] = f[i - 1][w[i]] + f[i][w[i] - w[i]];
        for (int j = 1; j <= max_m; ++j) {
            
        }
    }
    return 0;
}
