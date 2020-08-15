/*************************************************************************
	> File Name: EP20.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 31 May 2020 04:49:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define max_n 170

int num[max_n + 5] = {1, 1, 0};

void func(int *arr) {
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= arr[0]; j++) arr[j] *= i;
        for (int j = 1; j <= arr[0]; j++) {
            if (arr[j] < 10) continue;
            arr[j + 1] += arr[j] / 10;
            arr[j] %= 10;
            arr[0] += (arr[0] == j);
            
        }
    }
    return ;
}

int main() {
    int sum = 0;
    func(num);
    for (int i = 1; i <= num[0]; i++) {
        sum += num[i];
    }
    cout << sum << endl;
    return 0;
}
