/*************************************************************************
	> File Name: EP43.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 06 Jun 2020 04:17:33 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define max_n 1000

/*int digits(int n) {
    if (n == 0) return 1;
    return floor(log10(n)) + 1;
}*/

typedef long long ll;

ll add_to_num(int *num) {
    ll ret = 0;
    for (int i = 0; i < 10; i++) {
        ret = ret * 10 + num[i];
    }
    return ret;
}

int is_val(int *num, int *prime) {
    int flag = 1;
    for (int i = 1; flag && i < 8; i++) {
        int tmp = num[i] * 100 + num[i + 1] * 10 + num[i + 2];
        flag = !(tmp % prime[i]);
    }
    return flag;
}

/*int get_num(int x) {
    init();
    int n = 0, ans;
    while (digits(n) < 9) {
        n += 1;
        ans = ans;
        return 0;
    }
    return ans;
}*/

int main() {
    int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int prime[8] = {7, 2, 3, 5, 7, 11, 13, 17};
    int cnt = 1;
    ll sum = 0;
    do {
        if (is_val(num, prime)) sum += add_to_num(num);
        cnt += 1;
    } while (next_permutation(num, num + 10));
    cout << sum << endl;
    cout << "cnt : " << cnt << endl;
   /* for (int i = 0; i < 10; i++) {
        cnt += (get_num(i));
    }
    cout << cnt << endl;*/
    return 0;
}
